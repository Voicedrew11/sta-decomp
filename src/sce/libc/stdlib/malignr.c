/* libc.a member malignr.o (SAB: not in kfiv-decomp): newlib's mallocr.c
 * built with DEFINE_MEMALIGN.  unsigned long and long are 64-bit here, which
 * is where the __umoddi3 call and the 64-bit remainder size come from. */
#include <reent.h>
#include <libc_internal.h>

void __malloc_lock(Reent *ptr);
void __malloc_unlock(Reent *ptr);
void _free_r(Reent *ptr, void *p);

#define SIZE_SZ (sizeof(INTERNAL_SIZE_T))
#define MALLOC_ALIGNMENT 16
#define MALLOC_ALIGN_MASK (MALLOC_ALIGNMENT - 1)
#define MINSIZE 16
#define PREV_INUSE 0x1
#define SIZE_BITS 0x3
#define request2size(req)                                                                          \
    (((long)((req) + (SIZE_SZ + MALLOC_ALIGN_MASK)) < (long)(MINSIZE + MALLOC_ALIGN_MASK))         \
         ? MINSIZE                                                                                 \
         : (((req) + (SIZE_SZ + MALLOC_ALIGN_MASK)) & ~(MALLOC_ALIGN_MASK)))
#define mem2chunk(mem) ((mchunkptr)((char *)(mem) - 2 * SIZE_SZ))
#define chunk2mem(p) ((void *)((char *)(p) + 2 * SIZE_SZ))
#define chunksize(p) ((p)->size & ~(SIZE_BITS))
#define chunk_at_offset(p, s) ((mchunkptr)(((char *)(p)) + (s)))
#define set_head(p, s) ((p)->size = (s))
#define set_head_size(p, s) ((p)->size = (((p)->size & PREV_INUSE) | (s)))
#define set_inuse_bit_at_offset(p, s) (((mchunkptr)(((char *)(p)) + (s)))->size |= PREV_INUSE)
#define long_sub_size_t(x, y)                                                                      \
    (sizeof(long) > sizeof(INTERNAL_SIZE_T) && x < y ? -(long)(y - x) : (long)(x - y))

void *_memalign_r(Reent *reent_ptr, unsigned int alignment, unsigned int bytes)
{
    INTERNAL_SIZE_T nb; /* padded  request size */
    char *m;            /* memory returned by malloc call */
    mchunkptr p;        /* corresponding chunk */
    char *brk;          /* alignment point within p */
    mchunkptr newp;     /* chunk to return */
    INTERNAL_SIZE_T newsize;  /* its size */
    INTERNAL_SIZE_T leadsize; /* leading space befor alignment point */
    mchunkptr remainder;      /* spare room at end to split off */
    long remainder_size;      /* its size */

    if (alignment <= MALLOC_ALIGNMENT)
        return _malloc_r(reent_ptr, bytes);
    if (alignment < MINSIZE)
        alignment = MINSIZE;
    nb = request2size(bytes);
    m = (char *)(_malloc_r(reent_ptr, nb + alignment + MINSIZE));
    if (m == 0)
        return 0; /* propagate failure */
    __malloc_lock(reent_ptr);
    p = mem2chunk(m);
    if ((((unsigned long)(m)) % alignment) != 0) { /* misaligned */
        brk = (char *)mem2chunk(((unsigned int)(m + alignment - 1)) & -alignment);
        if ((long)(brk - (char *)(p)) < (long)MINSIZE)
            brk = brk + alignment;
        newp = (mchunkptr)brk;
        leadsize = brk - (char *)(p);
        newsize = chunksize(p) - leadsize;
        set_head(newp, newsize | PREV_INUSE);
        set_inuse_bit_at_offset(newp, newsize);
        set_head_size(p, leadsize);
        _free_r(reent_ptr, chunk2mem(p));
        p = newp;
    }
    remainder_size = long_sub_size_t(chunksize(p), nb);
    if (remainder_size >= (long)MINSIZE) {
        remainder = chunk_at_offset(p, nb);
        set_head(remainder, remainder_size | PREV_INUSE);
        set_head_size(p, nb);
        _free_r(reent_ptr, chunk2mem(remainder));
    }
    __malloc_unlock(reent_ptr);
    return chunk2mem(p);
}

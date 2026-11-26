#include "common.h"
typedef union { u64 d; struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:1; u8 b6:1; u8 b7:1; } b; } F;
typedef struct { Mtx m; Mtx x40; Mtx x80; u8 padC0[0x70]; u8 x130; u8 x131; u8 pad132[6]; F f; } Bone;
typedef struct { u8 pad[6]; u16 h6; u8 pad8[0x1C]; u8 lo:6; u8 c:2; u8 pad25[0xB]; Vec x30; } Hdr;
typedef struct { u8 pad[0x2A]; u8 x2A; u8 pad2B; u8 t:3; } Res;
typedef struct { u8 pad[0x180]; u8 x180[0x1C]; s8 *x19C; u8 pad1A0[8]; Hdr *x1A8; } Sub;
typedef struct { u8 pad[0x9A]; u8 x9A[0x47E]; Sub *x518; } A;
typedef struct { u8 pad[0x2AD]; u8 lo:3; u8 b3:1; } Q;
extern s32 D_00201F2C;
extern Mtx D_001F2170;
void sceVu0CopyMatrix(Bone *, Mtx *);
void sceVu0AddVector(Vec *, Vec *, Vec *);
void sceVu0CopyVector(Vec *, Vec *);
void sceVu0MulMatrix(Bone *, void *, Mtx *);
Vec *func_0013FFB0(A *);
Vec *func_0013FFA0(A *);
Res *func_0013DCA0(A *, u8);
void func_00136DB0(A *, Bone *);

void func_001370A0(A *a) {
    F f0;
    F pf;
    F f;
    Bone *bones;
    u8 done;
    u8 i;
    Bone *b;
    u8 *s7;
    u8 c;
    Hdr *h;

    done = 0;
    h = a->x518->x1A8;
    s7 = a->x518->x180;
    bones = (Bone *)((u8 *)((s32)h + 0x40) + D_00201F2C * (h->h6 * 0x140 + 0x200) + 0xC0);
    c = h->c;
    if (c) h->c--;
    sceVu0CopyMatrix(bones, &D_001F2170);
    sceVu0AddVector(&bones->m.m[3], &bones->m.m[3], &h->x30);
    sceVu0CopyVector(func_0013FFB0(a), &bones->m.m[3]);
    sceVu0CopyVector(func_0013FFA0(a), &bones->m.m[3]);
    f0.d = bones->f.d;
    f0.b.b5 = 0;
    f0.b.b2 = 0;
    if (f0.b.b4) f0.b.b5 = 1;
    if (f0.b.b1) f0.b.b2 = 1;
    bones->f.d = f0.d;
    for (i = 1; i < h->h6 + 1; i++) {
        b = &bones[i];
        f.d = b->f.d;
        pf.d = bones[b->x131].f.d;
        f.b.b5 = 0;
        f.b.b2 = 0;
        if (f.b.b4) f.b.b5 = 1;
        if (f.b.b1) f.b.b2 = 1;
        if (!f.b.b6) {
            u8 k;
            Res *r;
            sceVu0MulMatrix(b, &bones[b->x131], &b->x80);
            if (pf.b.b5) f.b.b5 = 1;
            if (pf.b.b2) f.b.b2 = 1;
            b->f.d = f.d;
            k = b->x130;
            r = func_0013DCA0(a, a->x9A[k]);
            if (r->x2A == k) {
                if (r->t == 2) {
                    if (done == 0) sceVu0CopyVector(func_0013FFB0(a), &b->m.m[3]);
                    sceVu0CopyVector(func_0013FFA0(a), &b->m.m[3]);
                }
                if (r->t == 5) {
                    if (((Q *)*(s8 **)(s7 + 0x1C))->b3) func_00136DB0(a, b);
                    sceVu0CopyVector(func_0013FFB0(a), &b->m.m[3]);
                    done = 1;
                }
            }
        } else {
            u8 k;
            Res *r;
            sceVu0MulMatrix(b, &b->x40, &b->x80);
            b->f.d = f.d;
            k = b->x130;
            r = func_0013DCA0(a, a->x9A[k]);
            if (r->x2A == k && r->t == 5) {
                sceVu0CopyVector(func_0013FFB0(a), &bones[b->x131].m.m[3]);
                done = 1;
            }
        }
    }
}

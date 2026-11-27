#include "common.h"
#include "m2c.h"
typedef struct { char pad[0x40]; char sub[0x210]; } E_func_00189020;
typedef struct { char pad[0x250]; } E_func_00189050;
typedef struct { s32 pad0; s32 a0; u8 pad8[0x28]; } Item;
typedef struct { u32 n; Item *items; } Grp;
typedef struct { s32 idx; u8 pad4[0x3C]; } Ent_func_00189080;
typedef struct { u32 n; Ent_func_00189080 *e; } List;
typedef struct { s32 n; u8 *p; } Hdr;
typedef struct { s32 n; u8 *p; } Ent_func_00189740;
typedef struct { Hdr *x[16]; Ent_func_00189740 e[64]; u8 **a; s32 pad; u32 n; } Tbl;
typedef struct { s32 f0; s32 f4; u64 f8; u8 pad[0x28]; } E_func_00189D50;
typedef struct { u32 n; E_func_00189D50 *e; } T;
typedef struct { u32 idx; u8 pad[0x3C]; } I;
typedef struct { u32 n; I *i; } A;
typedef struct { u8 b[4]; } Buf;
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; } B_func_00189F40;
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; } B_func_0018A650;
typedef struct { u8 pad[0x14]; B_func_0018A650 x14; } Arg;
extern volatile u32 D_004A0B0C[];
extern f32 D_002020D4;
extern s32 D_002020E8;
extern s32 D_002020DC;
extern u32 D_004A01D8[];
extern s32 D_004A01DC[];
extern u32 D_0049FF88[];
extern u32 D_0049FD38[];
extern s32 D_004A08C4[];
extern s32 D_0049FD3C[];
extern s32 D_0049FF8C[];
extern s32 D_004A08CC[];
extern u32 D_0049FAE8[];
extern s32 D_0049FAEC[];
extern u32 D_004A0428[];
extern s32 D_004A042C[];
extern u32 D_004A0678[];
extern s32 D_004A067C[];
extern s32 D_002020E0;
extern s32 D_00497B60[];
extern f32 D_004A0B10[];
extern f32 D_004A0B14[];
extern f32 D_004A0B18[];
extern f32 D_004A0B1C[];
extern M2C_UNK D_001F27B0[];
extern M2C_UNK D_001F27C0[];
extern s32 D_00201CF0;
extern f32 D_0020210C;
extern f32 D_00202110;
extern f32 D_00202114;
extern B_func_00189F40 D_004A0B34[];
extern u8 D_004A0B2A[];
extern s8 D_004A0B2C[];
extern s32 D_004A0AE8[];
extern s32 D_004A0AEC[];
extern s8 D_004A0B20[];
extern void (*D_001F2930[])(void *);
extern void (*D_001F2880[])(void *);
extern s32 D_004A0B24[];
extern u8 D_004A0B2B[];
extern void (*D_001F27D0[])(void *);
extern s32 D_002020F0;
extern u8 D_004A0B28[];
extern s8 D_004A0B2F[];
extern s8 D_004A0B29[];
extern s8 D_004A0B2E[];
extern s32 D_004A0B30[];
extern s32 D_00201CF4;
extern f32 D_002020D8;
extern f32 D_00202108;
extern f32 D_001F29E0[];
extern f32 D_001F29E4[];
extern f32 D_001F29E8[];
extern f32 D_001F29EC[];
extern f32 D_00202104;
extern s64 D_002020F8;
extern s32 D_00202100;
extern u16 D_00317230[];
extern u16 D_00317238[];
extern u16 D_0031723A[];
extern f32 D_00317244[];
extern f32 D_00317248[];
void func_00188F80(void);
s32* func_00188FF0(void);
s32* func_00189000(s32 arg0);
void* func_00189020(s32 i);
E_func_00189050* func_00189050(s32 i);
void func_00189080(void);
void func_001891C0(void);
void func_00189270(void);
void func_00189580(void);
void func_00189740(Tbl *t, u64 key);
void func_00189AD0(s32 *arg0);
s32 func_00189D50(A *a, T *t, s32 k);
void func_00189E90(void);
s32 func_00189EA0(void);
void func_00189ED0(s32 v);
void func_00189F00(void *arg0);
void func_00189F40(void);
void func_0018A200(void);
void func_0018A310(s32 arg0);
u8 func_0018A320(void);
void func_0018A330(s8 arg0);
void func_0018A350(s8 arg0);
void func_0018A410(s32 arg0);
void func_0018A420(s32 *a0);
void func_0018A580(s32 arg0, f32 *arg1, f32 min, f32 max, f32 step);
void func_0018A650(Arg *arg0);
void func_0018A910(void);
void func_0018AAD0(s32 *arg0);
void func_00128580(s32, s32);
void func_00177570(s32);
void func_00159DD0(s32, s32, s32 *, s32 *);
void func_00182990(s32 *);
void func_0018AEA0(s32 *);
void func_00180F40(void);
void func_001E1760(s32 *);
s32 func_00177AF0(u64, s32);
s32 func_00177B20(u64);
void func_00182080(f32, s32, void *, void *, void *, s32);
void func_00181420(void);
void func_00154700(s32, s32);
void func_001545D0(void);
void func_001543E0(s32, s32);
void func_001544C0(void);
void func_001DD700(s32, s8);
void func_00187B20(s32);
u8 func_001A9430(void);
void func_00157110(u8);
void func_00155900(void);
void func_0018E460(void);
void func_001304C0(void);
void func_0018E450(void);
void func_00182050(s32);
void func_0018B0C0();
void func_00199170(s32 *);
void func_0019A7E0(s32 *);
void func_0019DF80(s32 *);
void func_0019E8A0(s32 *);
void func_001A8B90(s32);
void func_001A8F00(s32);
void func_0012C0A0(void);
void func_00130440(void);
void func_0012C070(s32);
void func_001AB280(void);
f32 fabsf(f32);
void func_00186E70(f32);
void func_00186F20(f32);
void func_00186FD0(f32);
void func_00187080(f32);
f32 func_00187770(f32, f32, f32);
s32 func_00183FF0(void);

/* .bss from 0x00497B80, defined from the top down (CodeWarrior writes
   uninitialised objects in reverse order) */
s16 D_004A0AF0[0xe];
s32 D_004A0AE0[0x4];      /* also D_004A0AE8, D_004A0AEC */
u8 D_004A0950[0x190];
u8 D_004A0900[0x50];
u32 D_004A08C8[0xe] __attribute__((aligned(8)));
u8 D_004A06C0[0x208];      /* also D_004A08C4 */
s32 D_004A0680[0x10];
s32 D_004A0674[0x3] __attribute__((aligned(4)));      /* also D_004A0678, D_004A067C */
s32 D_004A0470[0x81];
s32 D_004A0430[0x10];
s32 D_004A0424[0x3] __attribute__((aligned(4)));      /* also D_004A0428, D_004A042C */
s32 D_004A0220[0x81];
s32 D_004A01E0[0x10];
s32 D_004A01D4[0x3] __attribute__((aligned(4)));      /* also D_004A01D8, D_004A01DC */
u8 D_0049FFD0[0x204];
s32 D_0049FF90[0x10];
s32 D_0049FF84[0x3] __attribute__((aligned(4)));      /* also D_0049FF88, D_0049FF8C */
u8 D_0049FD80[0x204];
s32 D_0049FD40[0x10];
s32 D_0049FD34[0x3] __attribute__((aligned(4)));      /* also D_0049FD38, D_0049FD3C */
u8 D_0049FB30[0x204];
s32 D_0049FAF0[0x10];
s32 D_0049FAE4[0x3] __attribute__((aligned(4)));      /* also D_0049FAE8, D_0049FAEC */
s32 D_0049F8E0[0x81];
/* 0x0049F8E0..0x004A06C0 is six 0x250-byte records, likely one
   struct { u8 buf[0x204]; s32 a; u32 b; s32 c; s32 d[0x10]; } [6]
   (buf at +0, a/b/c at +0x204, d at +0x210); the code still names each
   field of each record, so the objects stay separate until it is
   rewritten to index the records. */
u8 D_0049F8A0[0x40];
s32 D_00497C80[0x1f08];
s32 D_00497B80[0x40];

/* func_00188F80 */
void func_00188F80(void)
{
    D_004A0B0C[0] = 60;
    D_002020D4 += 60.0f / D_004A0B0C[0];
    func_0018A200();
}

/* func_00188FF0 */
s32 *func_00188FF0(void) {
    return &D_002020E8;
}

/* func_00189000 */
/* .bss, from the top down (CodeWarrior writes it in reverse) */

s32 *func_00189000(s32 arg0) {
    if (arg0 != 0) {
        return D_00497B80;
    }
    return D_00497C80;
}

/* func_00189020 */
#define D_0049F8A0 D_0049F8A0__as_func_00189020
extern E_func_00189020 D_0049F8A0__as_func_00189020[];

void *func_00189020(s32 i)
{
    return D_0049F8A0[i].sub;
}
#undef D_0049F8A0

/* func_00189050 */
#define D_0049F8A0 D_0049F8A0__as_func_00189050
extern E_func_00189050 D_0049F8A0__as_func_00189050[];

E_func_00189050 *func_00189050(s32 i)
{
    return &D_0049F8A0[i];
}
#undef D_0049F8A0

/* func_00189080 */

void func_00189080(void) {
    List **pl;
    Grp *grps;
    u32 i;
    List *l;
    u32 j;
    u32 k;
    Grp *g;

    i = 0;
    if (i < D_004A01D8[0]) {
        pl = D_0049F8A0;
        grps = D_0049FFD0;
        do {
            l = pl[0x1BC];
            if (l != NULL) {
                for (j = 0; j < l->n; j++) {
                    g = &grps[l->e[j].idx];
                    for (k = 0; k < g->n; k++) {
                        if (g->items[k].a0 != 0) {
                            func_00177570(g->items[k].a0);
                        }
                    }
                }
            }
            i++;
            pl++;
        } while (i < D_004A01D8[0]);
    }
    func_00128580(D_002020DC, D_004A01D4[0]);
}

/* func_001891C0 */
#define func_00189D50 func_00189D50__as_func_001891C0
void func_00189D50__as_func_001891C0(s32, s32 *, s32);
void func_001891C0(void) {
    u32 i;
    s32 *pl;
    s32 *g;
    s32 a;
    s32 b;
    a = 0;
    b = 0;
    func_00159DD0(0x45E87010, D_002020DC, &a, &b);
    i = 0;
    if (i < D_004A01D8[0]) {
        pl = D_0049F8A0;
        g = D_0049FFD0;
        do {
            func_00189D50(pl[0x1BC], g, a);
            i++;
            pl++;
        } while (i < D_004A01D8[0]);
    }
    D_004A01D4[0] = a;
    D_004A01DC[0] = b;
}
#undef func_00189D50

/* func_00189270 */

void func_00189270(void) {

    {
    List **pl;
    Grp *grps;
    u32 i;
    List *l;
    u32 j;
    u32 k;
    Grp *g;
    i = 0;
    if (i < D_0049FF88[0]) {
        pl = D_0049F8A0;
        grps = D_0049FD80;
        do {
            l = pl[0x128];
            if (l != NULL) {
                for (j = 0; j < l->n; j++) {
                    g = &grps[l->e[j].idx];
                    for (k = 0; k < g->n; k++) {
                        if (g->items[k].a0 != 0) {
                            func_00177570(g->items[k].a0);
                        }
                    }
                }
            }
            i++;
            pl++;
        } while (i < D_0049FF88[0]);
    }
    }
    func_00128580(D_002020DC, D_0049FF84[0]);

    {
    List **pl;
    Grp *grps;
    u32 i;
    List *l;
    u32 j;
    u32 k;
    Grp *g;
    i = 0;
    if (i < D_0049FD38[0]) {
        pl = D_0049F8A0;
        grps = D_0049FB30;
        do {
            l = pl[0x94];
            if (l != NULL) {
                for (j = 0; j < l->n; j++) {
                    g = &grps[l->e[j].idx];
                    for (k = 0; k < g->n; k++) {
                        if (g->items[k].a0 != 0) {
                            func_00177570(g->items[k].a0);
                        }
                    }
                }
            }
            i++;
            pl++;
        } while (i < D_0049FD38[0]);
    }
    }
    func_00128580(D_002020DC, D_0049FD34[0]);

    {
    List **pl;
    Grp *grps;
    u32 i;
    List *l;
    u32 j;
    u32 k;
    Grp *g;
    i = 0;
    if (i < D_004A08C8[0]) {
        pl = D_0049F8A0;
        grps = D_004A06C0;
        do {
            l = pl[0x378];
            if (l != NULL) {
                for (j = 0; j < l->n; j++) {
                    g = &grps[l->e[j].idx];
                    for (k = 0; k < g->n; k++) {
                        if (g->items[k].a0 != 0) {
                            func_00177570(g->items[k].a0);
                        }
                    }
                }
            }
            i++;
            pl++;
        } while (i < D_004A08C8[0]);
    }
    }
    func_00128580(D_002020DC, D_004A08C4[0]);
}

/* func_00189580 */
#define D_002020DC D_002020DC__as_func_00189580
extern s32 *D_002020DC__as_func_00189580;
#define func_00159DD0 func_00159DD0__as_func_00189580
void func_00159DD0__as_func_00189580(s32, s32 *, s32 *, s32 *);
#define func_00189D50 func_00189D50__as_func_00189580
void func_00189D50__as_func_00189580(s32, s32 *, s32);

void func_00189580(void) {
    s32 a; s32 b; s32 c; s32 d; s32 e; s32 f;
    u32 i; s32 *p; s32 *q;
    a = 0; b = 0;
    func_00159DD0(0x0EBC6141, D_002020DC, &a, &b);
    i = 0; if (i < D_0049FF88[0]) { p = D_0049F8A0; q = D_0049FD80; do { func_00189D50(p[0x128], q, a); i++; p++; } while (i < D_0049FF88[0]); }
    c = 0; d = 0;
    D_0049FF84[0] = a; D_0049FF8C[0] = b;
    func_00159DD0(0xF732041D, D_002020DC, &c, &d);
    i = 0; if (i < D_0049FD38[0]) { p = D_0049F8A0; q = D_0049FB30; do { func_00189D50(p[0x94], q, c); i++; p++; } while (i < D_0049FD38[0]); }
    e = 0; f = 0;
    D_0049FD34[0] = c; D_0049FD3C[0] = d;
    func_00159DD0(0x90BC19D0, D_002020DC, &e, &f);
    i = 0; if (i < D_004A08C8[0]) { p = D_0049F8A0; q = D_004A06C0; do { func_00189D50(p[0x378], q, e); i++; p++; } while (i < D_004A08C8[0]); }
    D_004A08C4[0] = e; D_004A08CC[0] = f;
}
#undef func_00159DD0
#undef func_00189D50
#undef D_002020DC

/* func_00189740 */
#define D_002020DC D_002020DC__as_func_00189740
extern s32 *D_002020DC__as_func_00189740;
#define func_00159DD0 func_00159DD0__as_func_00189740
void func_00159DD0__as_func_00189740(s32, s32 *, u8 ***, s32 *);

static inline u8 *hdr2(Tbl *t, u32 j, u8 *p) { u8 *q; t->x[j] = (Hdr *)p; q = p + 0x10; t->x[j]->p = q; return q + t->x[j]->n * 0x40; }
void func_00189740(Tbl *t, u64 key) {
    s32 b;
    u8 **a;
    u32 i;
    u32 n;
    u8 *p; u32 j; u32 m;
    b = 0;
    a = 0;
    func_00159DD0((s32)key, D_002020DC, &a, &b);
    p = *a;
    n = *(u32 *)p;
    p += 0x10;
    for (i = 0; i < n; i++) {
        t->e[i].n = *(s32 *)p;
        t->e[i].p = p + 0x10;
        p += t->e[i].n * 0x30 + 0x10;
    }
    m = *(u32 *)p;
    p += 0x10;
    for (j = 0; j < m; j++) {
p = hdr2(t, j, p);
    }
    t->n = m;
    t->a = a;
}
#undef func_00159DD0
#undef D_002020DC

/* func_00189AD0 */
#define D_002020DC D_002020DC__as_func_00189AD0
extern s32 *D_002020DC__as_func_00189AD0;
#define func_00159DD0 func_00159DD0__as_func_00189AD0
void func_00159DD0__as_func_00189AD0(s32, s32 *, s32 *, s32 *);
#define func_00189D50 func_00189D50__as_func_00189AD0
void func_00189D50__as_func_00189AD0(s32, s32 *, s32);
#define func_0018A410 func_0018A410__as_func_00189AD0
void func_0018A410__as_func_00189AD0(s32 *);

void func_00189AD0(s32 *arg0) {
    s32 a; s32 b; s32 c; s32 d; s32 e; s32 f;
    u32 i; s32 *p; s32 *r; s32 *q; u32 j;
    D_002020DC = arg0;
    func_00189740(D_0049F8A0, 0x13BCC6E4);
    a = 0; b = 0;
    func_00159DD0(0x13BD5472, D_002020DC, &a, &b);
    i = 0; if (i < D_0049FAE8[0]) { p = D_0049F8A0; do { func_00189D50(p[0], D_0049F8E0, a); i++; p++; } while (i < D_0049FAE8[0]); }
    D_0049FAE4[0] = a; D_0049FAEC[0] = b;
    func_00189740(D_004A0430, 0x9D2D9756);
    c = 0; d = 0;
    func_00159DD0(0x9D2C05C0, D_002020DC, &c, &d);
    j = 0; if (j < D_004A0678[0]) { r = D_0049F8A0; q = D_004A0470; do { func_00189D50(r[0x2E4], q, c); j++; r++; } while (j < D_004A0678[0]); }
    D_004A0674[0] = c; D_004A067C[0] = d;
    func_00189740(D_004A01E0, 0x0178F67D);
    e = 0; f = 0;
    func_00159DD0(0x017964EB, D_002020DC, &e, &f);
    j = 0; if (j < D_004A0428[0]) { r = D_0049F8A0; q = D_004A0220; do { func_00189D50(r[0x250], q, e); j++; r++; } while (j < D_004A0428[0]); }
    D_004A0424[0] = e; D_004A042C[0] = f;
    func_00189740(D_0049FD40, 0x0EBDF3D7);
    func_00189740(D_0049FAF0, 0xF733968B);
    func_00189740(D_004A0680, 0x90BD8B46);
    func_00189740(D_0049FF90, 0x45E9E286);
    func_00182990(D_002020DC);
    func_0018A410(D_002020DC);
    func_0018AEA0(D_002020DC);
    func_00180F40();
    func_001E1760(D_002020DC);
}
#undef func_00159DD0
#undef func_00189D50
#undef func_0018A410
#undef D_002020DC

/* func_00189D50 */
s32 func_00189D50(A *a, T *t, s32 k) {
    u32 i, j;
    if (a == 0) return 1;
    for (i = 0; i < a->n; i++) {
        T *tt = &t[a->i[i].idx];
        for (j = 0; j < tt->n; j++) {
            E_func_00189D50 *e = (E_func_00189D50 *)((u8 *)tt->e + j * 0x30);
            e->f4 = 0;
            if (e->f8 != -1 && e->f8 != 0) {
                if (k) e->f4 = func_00177AF0(e->f8, k);
                else e->f4 = func_00177B20(e->f8);
            }
        }
    }
    return 0;
}

/* func_00189E90 */
void func_00189E90(void) {
    D_002020E0 = 0;
}

/* func_00189EA0 */
s32 func_00189EA0(void)
{
    D_002020E0--;
    return D_00497B60[D_002020E0];
}

/* func_00189ED0 */
void func_00189ED0(s32 v)
{
    D_00497B60[D_002020E0] = v;
    D_002020E0++;
}

/* func_00189F00 */
void func_00189F00(void *arg0) {
    (*D_004A0B10) = M2C_FIELD(arg0, f32 *, 0);
    (*D_004A0B14) = M2C_FIELD(arg0, f32 *, 4);
    (*D_004A0B18) = M2C_FIELD(arg0, f32 *, 8);
    (*D_004A0B1C) = M2C_FIELD(arg0, f32 *, 0xC);
}

/* func_00189F40 */

void func_00189F40(void) {
    Buf s;

    func_00154700(5, 0);
    func_001545D0();
    func_001543E0(0x42, 0x44);
    func_001544C0();
    func_0018A580(D_00201CF0 != 0x12 && D_00201CF0 != 0x28, &D_0020210C, 0.0f, 64.0f, 4.0f);
    func_0018A580(D_004A0B34[0].b4, &D_00202114, 0.0f, 128.0f, 2.0f);
    if (D_001F2930[D_00201CF0] != NULL) {
        D_004A0AE8[0] = 0;
        D_004A0AEC[0] = 0;
        D_001F2930[D_00201CF0](D_004A0B20);
        func_00181420();
    }
    func_0018A910();
    func_001DD700(D_00201CF0, D_004A0B2C[0]);
    func_00181420();
    if (D_001F2880[D_00201CF0] != NULL) {
        D_004A0AE8[0] = 0;
        D_004A0AEC[0] = 0;
        D_001F2880[D_00201CF0](D_004A0B20);
        func_00181420();
    }
    if (!D_004A0B34[0].b3) {
        func_0018A580(D_004A0B2A[0], &D_00202110, 0.0f, 64.0f, 4.0f);
        if (D_004A0B2A[0]) {
            D_001F2880[0](D_004A0B20);
            func_00187B20(0);
            func_00181420();
        }
        func_0018A650(D_004A0B20);
        func_00187B20(0);
        func_00181420();
        func_00157110((func_001A9430() - 0x20) * 2 + 0x80);
        if (!(D_004A0B1C[0] <= 0.0f)) {
            s.b[0] = (s32)(D_004A0B10[0] / 2.0f);
            s.b[1] = (s32)(D_004A0B14[0] / 2.0f);
            s.b[2] = (s32)(D_004A0B18[0] / 2.0f);
            s.b[3] = (s32)(D_004A0B1C[0] / 2.0f);
            func_00182080(0.0f, 0, D_001F27B0, D_001F27C0, &s, 0);
            func_00181420();
        }
    } else {
        D_004A0B34[0].b3 = 0;
    }
    func_00155900();
}

/* func_0018A200 */
#define D_004A0B20 D_004A0B20__as_func_0018A200
extern s32 D_004A0B20__as_func_0018A200[];

void func_0018A200(void) {
    func_0018E460();
    func_0018AAD0(D_004A0B20);
    switch (D_004A0B20[0]) {
    case 0:
        D_004A0B24[0] = 0;
        break;
    case 31:
    case 25:
    case 26:
    case 27:
    case 28:
    case 29:
    case 30:
        break;
    }
    if (D_004A0B2B[0] == 0) {
        D_001F27D0[D_00201CF0](D_004A0B20);
    }
    if (D_004A0B2A[0] != 0) {
        D_001F27D0[0](D_004A0B20);
    }
    D_004A0B24[0] = 0;
    func_0018A420(D_004A0B20);
    func_001304C0();
    func_0018E450();
}
#undef D_004A0B20

/* func_0018A310 */
void func_0018A310(s32 arg0) {
    D_002020F0 |= arg0;
}

/* func_0018A320 */
u8 func_0018A320(void) {
    return (*D_004A0B28);
}

/* func_0018A330 */
void func_0018A330(s8 arg0) {
    if (D_00201CF0 == 0x12) {
        (*D_004A0B2F) = arg0;
    }
}

/* func_0018A350 */
#define D_004A0B20 D_004A0B20__as_func_0018A350
extern s32 D_004A0B20__as_func_0018A350[];
#define D_004A0B34 D_004A0B34__as_func_0018A350
extern s32 D_004A0B34__as_func_0018A350[];

void func_0018A350(s8 arg0) {
    (*D_004A0B28) = arg0;
    (*D_004A0B29) = 0;
    (*D_004A0B20) = 0x1F;
    (*D_004A0B2E) = 0x7F;
    (*D_004A0B2F) = 0;
    (*D_004A0B2C) = 0;
    (*D_004A0B34) = 0;
    func_00182050(0x80);
    func_0019A7E0(D_004A0B20);
    func_0019E8A0(D_004A0B20);
    func_0019DF80(D_004A0B20);
    func_00199170(D_004A0B20);
    func_0018B0C0();
    (*D_004A0B10) = 0;
    (*D_004A0B14) = 0;
    (*D_004A0B18) = 0;
    (*D_004A0B1C) = 0;
}
#undef D_004A0B20
#undef D_004A0B34

/* func_0018A410 */
void func_0018A410(s32 arg0) {
    (*D_004A0B30) = arg0;
}

/* func_0018A420 */
/* .bss, from the top down (CodeWarrior writes it in reverse) */

void func_0018A420(s32 *a0) {
    switch (*a0) {
    case 0:
        *a0 = 0x16;
        break;
    case 0x19:
        if (D_00201CF4 != *a0) {
            D_004A0AE0[0] = 0;
            D_004A0AF0[0] = 3;
            D_002020D8 = D_002020D4;
        }
        *a0 = 0x1B;
        break;
    case 0x1A:
        *a0 = 0x1C;
        break;
    case 0x1B:
        if (!(D_00202108 <= 5.0f)) {
            D_00202108 = 0.0f;
            *a0 = 0;
        } else {
            D_00202108 += 1.0f;
        }
        break;
    case 0x1C:
        if (!(D_00202108 <= 12.0f)) {
            D_00202108 = 0.0f;
            *a0 = 0x1E;
        } else {
            D_00202108 += 1.0f;
        }
        break;
    case 0x1E:
        *a0 = 0x1F;
        break;
    case 0x21:
        D_002020D8 = D_002020D4;
        *a0 = 0x16;
        break;
    case 0x20:
        break;
    }
    D_00201CF4 = *a0;
}

/* func_0018A580 */
void func_0018A580(s32 arg0, f32 *arg1, f32 min, f32 max, f32 step) {
    f32 v = *arg1; Buf s = {0};
    if (arg0 != 0) {
        v += step;
        if (v > max) v = max;
    } else {
        v -= step;
        if (v < min) v = min;
    }
    s.b[3] = (s32)v;
    *arg1 = v;
    if (s.b[3] > 0) {
        func_00182080(0.0f, 0, D_001F27B0, D_001F27C0, &s, 0);
        func_00181420();
    }
}

/* func_0018A650 */
#define func_00189000 func_00189000__as_func_0018A650
s32 func_00189000__as_func_0018A650(s32);

void func_0018A650(Arg *arg0) {
    Buf s = {0};

    if (arg0->x14.b2) {
        D_00202104 += 4.0f;
        if (D_00202104 > 128.0f) {
            func_00189E90();
            func_001A8B90(func_00189000(1));
            func_001A8F00(func_00189000(0));
            func_0012C0A0();
            func_00130440();
            D_001F29EC[0] = -2.89f;
            D_001F29E8[0] = -2.89f;
            D_001F29E4[0] = -2.89f;
            D_001F29E0[0] = -2.89f;
            D_004A0B34[0].b2 = 0;
        }
    } else if (D_004A0B34[0].b0) {
        D_00202104 += 4.0f;
        if (D_00202104 > 128.0f) {
            func_00189E90();
            func_0012C070(0);
            func_001AB280();
            func_00130440();
            D_001F29EC[0] = -2.89f;
            D_001F29E8[0] = -2.89f;
            D_001F29E4[0] = -2.89f;
            D_001F29E0[0] = -2.89f;
            D_004A0B34[0].b0 = 0;
        }
    } else if (D_004A0B34[0].b1) {
        D_00202104 += 4.0f;
        if (D_00202104 > 128.0f) {
            func_00189E90();
            func_0012C070(1);
            D_001F29EC[0] = -2.89f;
            D_001F29E8[0] = -2.89f;
            D_001F29E4[0] = -2.89f;
            D_001F29E0[0] = -2.89f;
            D_004A0B34[0].b0 = 0;
        }
    } else {
        D_00202104 -= 4.0f;
        if (D_00202104 < 0.0f) {
            D_00202104 = 0.0f;
        }
    }
    s.b[3] = (s32)D_00202104;
    if (s.b[3] > 0) {
        func_00182080(0.0f, 0, D_001F27B0, D_001F27C0, &s, 0);
        func_00181420();
    }
}
#undef func_00189000

/* func_0018A910 */
void func_0018A910(void) {
    s32 bit;
    f32 *p;

    bit = 1;
    p = D_001F29E0;
    do {
        if (D_002020F0 & bit) {
            *p = func_00187770(*p, -0.01f, 3.5f);
        } else {
            *p = func_00187770(*p, -2.89f, 3.5f);
        }
        bit += bit;
        p++;
    } while (bit < 0x10);
    if (!(fabsf(D_001F29E0[0] - -2.89f) <= 0.005f)) {
        func_00186F20(0.7f + D_001F29E0[0]);
    }
    if (!(fabsf(D_001F29E4[0] - -2.89f) <= 0.005f)) {
        func_00186E70(-D_001F29E4[0]);
    }
    if (!(fabsf(D_001F29E8[0] - -2.89f) <= 0.005f)) {
        func_00187080(D_001F29E8[0]);
    }
    if (!(fabsf(D_001F29EC[0] - -2.89f) <= 0.005f)) {
        func_00186FD0(-D_001F29EC[0]);
    }
    D_002020F0 = 0;
}

/* func_0018AAD0 */
void func_0018AAD0(s32 *arg0) {
    s64 v;

    if (arg0[0] == 0x1F) {
        if (func_00183FF0() != 0) return;
        arg0[0] = 0x19;
        D_00201CF0 = ((u8 *)arg0)[8];
    }
    arg0[1] = D_0031723A[0] | D_00317238[0];
    v = 0;
    if (D_00317244[0] < -0.9f && !(D_00317230[0] & 0x80)) v |= 0x80;
    if (!(D_00317244[0] <= 0.9f) && !(D_00317230[0] & 0x20)) v |= 0x20;
    if (D_00317248[0] < -0.9f && !(D_00317230[0] & 0x10)) v |= 0x10;
    if (!(D_00317248[0] <= 0.9f) && !(D_00317230[0] & 0x40)) v |= 0x40;
    if (v != 0) {
        if (D_002020F8 == v) {
            D_00202100++;
        } else {
            D_002020F8 = v;
            D_00202100 = 0;
        }
        if (D_00202100 != 0) {
            if (D_00202100 > 0xC) goto f;
        } else {
f:
            if (D_00202100 % 4 == 0) {
                arg0[1] |= (s32)v;
            }
        }
    } else {
        D_002020F8 = v;
    }
}

#include "common.h"
typedef struct { f32 x, y, z, w; } V4;
typedef struct { u16 a:1; u16 b:8; u16 c:1; u16 r:6; } BF;
typedef struct { u8 a; u8 b; u8 pad2[6]; s32 x8; u16 xC; u8 padE[10]; s32 x18; } Ent;
typedef s32 (*Fn)(Ent *);
typedef struct { u8 x0; u8 x1; u8 p2[6]; s32 x8; u8 pC[2]; u16 xE; s32 x10; s32 x14; } T;
extern s32 D_004BAC40[];
extern s32 D_004BAC44[];
extern s32 D_004BAC48[];
extern s32 D_002023A8;
extern V4 D_004BAC20[];
extern s32 D_004BAC30[];
extern s32 D_004BAC34[];
extern s32 D_004BAC38[];
extern BF D_004BAC4C[];
extern Fn D_004BAC28[];
extern Fn D_004BAC2C[];
extern s32 (*D_004BAC24[])(T *, s32);
void Task_SetCallback_1_001E0560(s32 arg0, s32 arg1);
void Task_Start_1_001E0590(s32 a0, s32 a1, s32 a2, V4 *v);
void Task_Schedule_1_001E0680(void);
s32 Task_Dispatch_0_001E0AB0(T *p);
void Task_RunAll_1_001DFCB0(s32);

/* Task_SetCallback_1_001E0560 */
void Task_SetCallback_1_001E0560(s32 arg0, s32 arg1) {
    if (arg0 != 0) {
        (*D_004BAC40) = arg0;
        (*D_004BAC44) = arg1;
        (*D_004BAC48) = -1;
    }
}

/* Task_Start_1_001E0590 */
void Task_Start_1_001E0590(s32 a0, s32 a1, s32 a2, V4 *v) {
    if (D_002023A8 == 0 && a0 != 0 && v != NULL) {
        D_004BAC20[0] = *v;
        D_004BAC38[0] = a2;
        D_004BAC34[0] = a1;
        D_004BAC30[0] = a0;
        D_004BAC4C[0].a = 0;
        D_004BAC4C[0].b = 0;
        D_004BAC4C[0].c = 0;
        Task_RunAll_1_001DFCB0(0);
        D_002023A8 = 1;
    }
}

/* Task_Schedule_1_001E0680 */
#define D_004BAC30 D_004BAC30__as_Task_Schedule_1_001E0680
extern u8 *D_004BAC30__as_Task_Schedule_1_001E0680[];
#define D_004BAC38 D_004BAC38__as_Task_Schedule_1_001E0680
extern u32 D_004BAC38__as_Task_Schedule_1_001E0680[];
#define Task_Dispatch_0_001E0AB0 Task_Dispatch_0_001E0AB0__as_Task_Schedule_1_001E0680
void Task_Dispatch_0_001E0AB0__as_Task_Schedule_1_001E0680(Ent *);

static inline s32 cb(Ent *e) {
    Fn f = D_004BAC2C[0];
    return f ? f(e) : 0;
}

static inline void get3(Ent **pe, u32 i) {
    *pe = (Ent *)(D_004BAC30[0] + D_004BAC34[0] * i);
}

static inline Ent *get(u32 i) {
    return (Ent *)(D_004BAC30[0] + D_004BAC34[0] * i);
}

void Task_Schedule_1_001E0680(void) {
    u32 i;
    Ent *p;
    u32 k;
    Ent *q;
    Ent *e;
    s32 j;
    s32 foundv;
    s32 minv;
    u32 found;
    u32 mi;

    minv = foundv = 0x10000;
    mi = found = -1;
    {
        for (j = 0; j < D_004BAC38[0]; j++) {
            get3(&e, j);
            if (e->a == 1 || e->a == 4) {
                if (found != -1) return;
                foundv = e->xC;
                found = j;
            } else if (e->b == 2 && e->xC < minv) {
                minv = e->xC;
                mi = j;
            }
        }
    }
    if (mi != -1 && minv < foundv) {
        if (found == -1) {
            e = get(mi);
            e->a = 1;
            Task_Dispatch_0_001E0AB0(e);
        } else {
            e = get(found);
            if (e->b == 2) e->b = 3;
        }
    } else if (found != -1) {
        e = get(found);
        if (cb(e) == 0 && e->b == 2) Task_Dispatch_0_001E0AB0(e);
    }
    for (i = 0; i < D_004BAC38[0]; i++) {
        q = get(i);
        if (q->b == 1) {
            if (q->a == 1 || q->a == 4) {
                if (cb(q) == 0) {
                    q->a = 0;
                    q->b = 0;
                    q->x18 = -1;
                    if (D_004BAC28[0]) D_004BAC28[0](q);
                }
            } else {
                q->a = 0;
                q->b = 0;
                q->x18 = -1;
                if (D_004BAC28[0]) D_004BAC28[0](q);
            }
        }
    }
    for (k = 0; k < D_004BAC38[0]; k++) {
        p = get(k);
        if (p->b == 3) {
            if (p->a == 1) {
                if (cb(p) == 0) {
                    p->a = 2;
                    p->b = 0;
                }
            } else if (p->a == 4) {
                if (cb(p) == 0) p->a = 5;
            } else {
                p->b = 0;
            }
        }
    }
    for (k = 0; k < D_004BAC38[0]; k++) {
        p = get(k);
        if (p->b == 4) {
            if (p->a == 6) {
                if (D_004BAC28[0]) D_004BAC28[0](p);
                p->a = 3;
                p->b = 0;
                p->x8 = 0;
            } else {
                p->b = 0;
            }
        }
    }
}
#undef Task_Dispatch_0_001E0AB0
#undef D_004BAC30
#undef D_004BAC38

/* Task_Dispatch_0_001E0AB0 */
#define D_004BAC28 D_004BAC28__as_Task_Dispatch_0_001E0AB0
extern s32 (*D_004BAC28__as_Task_Dispatch_0_001E0AB0[])(T *);

s32 Task_Dispatch_0_001E0AB0(T *p) {
    if (p == NULL) return -1;
    if (p->x14 == 0) return -1;
    if (p->x0 != 1) return -1;
    if (p->x1 != 2) return -1;
    if (D_004BAC24[0] != NULL) {
        if (D_004BAC24[0](p, 0x20000) != 0) {
            if (p->xE != 0) {
                p->x14 += 0x20000;
                p->x8 -= 0x20000;
            } else {
                p->x14 = p->x10;
                p->x8 -= 0x20000;
                p->x0 = 4;
                p->x1 = 3;
            }
            return 0;
        }
        if (D_004BAC28[0] != NULL) {
            if (D_004BAC28[0](p) != 0) {
                p->x0 = 3;
            } else {
                p->x0 = 6;
            }
        } else {
            p->x0 = 6;
        }
        p->x1 = 0;
        p->x8 = 0;
        return 1;
    }
    return -1;
}
#undef D_004BAC28

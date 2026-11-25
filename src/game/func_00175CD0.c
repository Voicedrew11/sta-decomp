#include "m2c.h"
typedef struct {
    u64 TBP0:14; u64 TBW:6; u64 PSM:6; u64 TW:4; u64 TH:4; u64 TCC:1; u64 TFX:2;
    u64 CBP:14; u64 CPSM:4; u64 CSM:1; u64 CSA:5; u64 CLD:3;
} Tex0;
typedef struct {
    u64 LCM:1; u64 p1:1; u64 MXL:3; u64 MMAG:1; u64 MMIN:3; u64 MTBA:1; u64 p2:9; u64 L:2; u64 p3:11;
    u64 K:12; u64 p4:20;
} Tex1;
typedef struct {
    u64 SBP:14; u64 p0:2; u64 SBW:6; u64 p1:2; u64 SPSM:6; u64 p2:2;
    u64 DBP:14; u64 p3:2; u64 DBW:6; u64 p4:2; u64 DPSM:6; u64 p5:2;
} Bbuf;
typedef struct { s32 x0; s32 x4; } Img;
typedef struct { u8 pad0[8]; s32 off[7]; s32 x24; Bbuf bb; Bbuf pb; u8 pad38[8]; } M;
typedef struct { u8 pad0[0x10]; M m; } Ent;
typedef struct {
    Tex0 t0;
    Tex1 t1;
    Img *x10;
    u8 pad14[0xC];
    u16 h20;
    s16 h22;
    s32 x24;
    u8 x28;
    u8 pad29;
    u16 h2A;
    u16 h2C;
    u16 h2E;
} T;
typedef struct { T *t; s32 x4; s32 x8; } A;
typedef struct { s16 prev, next, fnext, fprev; u16 off, size; void *owner; } Blk;
typedef union { u128 q; struct { u32 a; u32 b; u64 c; } s; } Tag;
extern s16 D_00222A1A[];
extern s32 D_004830E0[];
extern s32 D_004830E4[];
extern s32 D_004830E8[];
extern s32 D_004830EC[];
extern volatile s16 D_004830DC[];
#define D_004830DC D_004830DC[0]
extern s16 D_004830DE[];
#define D_004830DE D_004830DE[0]
extern Blk D_0047F0C0[];
void func_001542D0(void);
void func_001541F0(s32, Bbuf);
void func_00154230(void);
u128 *func_001543A0(s32);
void func_00154390(void);
void func_00154310(s32);
u16 func_00176BF0(T *, u16);

void func_00175CD0(A *a0) {
    s32 h;
    s32 d;
    T *t;
    s32 base;
    M *m;
    s32 dbp;
    u32 dbw;
    s32 *o;
    u32 off;
    s16 n;
    s16 f;
    u16 v;
    Bbuf bb1;
    Bbuf bb2;
    Bbuf bb3;
    Tag tag;
    Tag *p;

    t = a0->t;
    if (t == NULL) return;
    if (t->t1.MXL != 0 && D_00222A1A[0] != -1) {
        t->t1.LCM = 1;
        t->t1.K = *(volatile s16 *)D_00222A1A << 4;
    } else {
        t->t1.LCM = 0;
        t->t1.K = 0;
    }
    if ((t->x28 & 7) == 1) {
        if (t->h22 != -1) {
            D_004830E8[0]++;
            D_004830EC[0]++;
            func_001542D0();
            func_001541F0(0x14, *(Bbuf *)&t->t1);
            func_001541F0(6, *(Bbuf *)&t->t0);
            func_00154230();
            n = t->h22;
            if (n != D_004830DC) {
                D_004830DE--;
                if (n == D_0047F0C0[n].fnext) {
                    D_004830DC = -1;
                } else {
                    D_0047F0C0[D_0047F0C0[n].fnext].fprev = D_0047F0C0[n].fprev;
                    D_0047F0C0[D_0047F0C0[n].fprev].fnext = D_0047F0C0[n].fnext;
                    if (D_004830DC == n) D_004830DC = D_0047F0C0[n].fnext;
                }
                D_004830DE++;
                f = D_004830DC;
                if (f == -1) {
                    D_004830DC = n;
                    D_0047F0C0[n].fnext = n;
                    D_0047F0C0[n].fprev = n;
                } else {
                    D_0047F0C0[n].fnext = f;
                    D_0047F0C0[n].fprev = D_0047F0C0[f].fprev;
                    D_0047F0C0[D_0047F0C0[n].fnext].fprev = n;
                    D_0047F0C0[D_0047F0C0[n].fprev].fnext = n;
                    D_004830DC = n;
                }
            }
        } else {
            v = func_00176BF0(t, (u32)(t->h2A + t->h2E + 15) >> 4);
            t->h22 = v;
            off = D_0047F0C0[v].off;
            base = t->x10->x0 + t->x24;
            m = (M *)(t->h20 * 0x50 + (t->x10->x0 + t->x24) + 0x10);
            d = t->x10->x4 - t->x10->x0;
            h = (t->h2C + 15) >> 4;
            dbp = off + ((t->h2E + 15) >> 4);
            bb1 = m->bb;
            func_001542D0();
            bb1.DBP = dbp;
            dbw = bb1.DBW;
            func_001541F0(0x50, bb1);
            func_00154230();
            p = (Tag *)func_001543A0(1);
            tag.s.a = 0x50000000;
            tag.s.b = d + (base + m->off[0]);
            tag.s.c = 0;
            *p = tag;
            func_00154390();
            for (o = (s32 *)m; o[3] != 0; o++) {
                dbp += h;
                h >>= 2;
                if (h == 0) h = 1;
                dbw >>= 1;
                if (dbw == 0) dbw = 1;
                bb2 = m->bb;
                func_001542D0();
                bb2.DBP = dbp;
                bb2.DBW = dbw;
                func_001541F0(0x50, bb2);
                func_00154230();
                p = (Tag *)func_001543A0(1);
                tag.s.a = 0x50000000;
                tag.s.b = d + (base + o[3]);
                tag.s.c = 0;
                *p = tag;
                func_00154390();
            }
            if (m->x24 != 0) {
                bb3 = m->pb;
                func_001542D0();
                bb3.DBP = off;
                func_001541F0(0x50, bb3);
                func_00154230();
                p = (Tag *)func_001543A0(1);
                tag.s.a = 0x50000000;
                tag.s.b = d + (base + m->x24);
                tag.s.c = 0;
                *p = tag;
                func_00154390();
            }
            func_001542D0();
            func_001541F0(0x14, *(Bbuf *)&t->t1);
            t->t0.TBP0 = off + ((t->h2E + 15) >> 4);
            t->t0.CBP = off;
            if (m->x24 != 0) {
                t->t0.CLD = 2;
                func_001541F0(6, *(Bbuf *)&t->t0);
                t->t0.CLD = 4;
            } else {
                t->t0.CLD = 0;
                func_001541F0(6, *(Bbuf *)&t->t0);
            }
            func_00154230();
            D_004830E8[0]++;
            D_004830EC[0]++;
            D_004830E0[0]++;
            D_004830E4[0]++;
        }
    }
    func_00154310(a0->x8);
}

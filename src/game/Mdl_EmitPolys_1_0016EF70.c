#include "m2c.h"
typedef union { u128 q; u64 d[2]; u32 w[4]; f32 f[4]; } Q;
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:1; u8 b6:1; u8 b7:1; u8 pad[3]; } F;
typedef struct { u8 pad[0xF]; F f; } Obj;
typedef struct { u16 x0; u16 x2; u16 x4; u16 x6; u16 x8; u16 xA; u16 xC; u16 xE; } E16;
typedef struct { E16 e; u8 pad[0x10]; } E32;
typedef struct { u8 pad[0x20]; } T;
extern s16 D_00222A18[];
extern s32 D_00202008;
extern T D_0042DDC0[];
Q *GsPkt_Alloc_3_00154A80(s32);
void GsPkt_Commit_1_00154A70(void);

void Mdl_EmitPolys_1_0016EF70(Obj *a0, E16 *a1, u8 *a2, u32 cnt, s32 off, F f) {
    E16 *e;
    u32 i;
    u8 *ad;
    Q *p;
    Q q;
    s32 idx = D_00222A18[0];
    if (idx == -1) {
        p = GsPkt_Alloc_3_00154A80(cnt * 2 + 1);
        for (i = 0; i < cnt; i++) {
            if ((*(Obj *volatile *)&a0)->f.b1) e = (E16 *)&((E32 *)a1)[i]; else e = &a1[i];
            ad = a2 + e->x4 * 16;
            q.q = 0;
            q.w[0] = 0x30000002;
            q.w[1] = (u32)&D_0042DDC0[e->x2 << 5 | f.b0 << 4 | f.b1 << 3 | f.b4 << 2 | f.b2 << 1 | f.b6];
            if (i != 0) {
                q.w[2] = D_00202008 | 0x15000000;
            }
            q.w[3] = 0x6C028000;
            p[0].q = q.q;
            q.q = 0;
            q.w[0] = e->x8 | 0x30000000;
            q.w[1] = (u32)(ad + off);
            p[1].q = q.q;
            p += 2;
            if (i == cnt - 1) {
                q.q = 0;
                q.w[0] = 0x10000000;
                q.w[3] = 0x10000000;
                q.w[2] = D_00202008 | 0x15000000;
                p[0].q = q.q;
                p++;
            }
        }
        GsPkt_Commit_1_00154A70();
    } else if (idx < (s32)cnt) {
        e = a0->f.b1 ? (E16 *)&((E32 *)a1)[idx] : &a1[idx];
        p = GsPkt_Alloc_3_00154A80(3);
        ad = a2 + e->x4 * 16;
        q.q = 0;
        q.w[0] = 0x30000002;
        q.w[1] = (u32)&D_0042DDC0[e->x2 << 5 | f.b0 << 4 | f.b1 << 3 | f.b4 << 2 | f.b2 << 1 | f.b6];
        q.w[3] = 0x6C028000;
        p[0].q = q.q;
        q.q = 0;
        q.w[0] = e->x8 | 0x30000000;
        q.w[1] = (u32)(ad + off);
        p[1].q = q.q;
        q.q = 0;
        q.w[0] = 0x10000000;
        q.w[3] = 0x10000000;
        q.w[2] = D_00202008 | 0x15000000;
        p[2].q = q.q;
        GsPkt_Commit_1_00154A70();
    }
}








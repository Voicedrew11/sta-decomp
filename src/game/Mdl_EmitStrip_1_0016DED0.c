#include "common.h"
typedef union { u128 q; u64 d[2]; u32 w[4]; } Q;
typedef union { u32 w; f32 f; struct { u16 p0:7; u16 a:4; u16 b11:1; u16 b12:1; u16 p1:3; u16 hi; } s; } P4;
typedef struct { u8 lo:3; u8 mid:3; u8 hi:2; } BF;
typedef struct { u8 pad[5]; u8 idx; u8 list[8]; BF f; } A0;
typedef struct { u8 pad[0x24]; Flags8 f; } A1;
typedef struct { u8 pad[0x100]; u8 m[0x10]; u8 x110[0x28]; Flags8 x138; u8 pad2[7]; } E;
typedef struct { u8 pad[0xB0]; u32 base; u8 pad2[0x200 - 0xB4]; E e[1]; } A2;
extern Flags8 D_00222A50[];
extern Flags8 D_00222A51[];
extern u32 D_00201F54;
extern u8 D_001F2110[];
Q *GsPkt_Alloc_3_00154A80(s32);
void GsPkt_Commit_1_00154A70(void);
void sceVu0CopyVector(void *, void *);

void Mdl_EmitStrip_1_0016DED0(A0 *a0, A1 *a1, A2 *a2, P4 a3) {
    Q q;
    Q r;
    P4 s;
    u32 n;
    u32 p;
    u32 i;
    u32 t;
    u8 c;

    n = a0->f.hi;
    if (!a1->f.f.b5) n = 0;
    p = (u32)GsPkt_Alloc_3_00154A80(n + 5 + (a0->f.lo != 0));
    q.q = 0;
    q.w[0] = 0x30000004;
    q.w[1] = (u32)&a2->e[a0->idx] + a2->base;
    q.w[3] = (0 * 4 + 0x18) | 0x6C040000;
    *(u128 *)p = q.q;
    p += 16;
    if (a2->e[a0->idx].x138.f.b6) {
        for (i = 0; i < n; i++) {
            q.w[0] = 0x30000004;
            q.w[1] = (u32)&a2->e[a0->idx] + a2->base;
            q.w[3] = ((i + 1) * 4 + 0x18) | 0x6C040000;
            *(u128 *)p = q.q;
            p += 16;
        }
    } else {
        for (i = 0; i < n; i++) {
            q.w[0] = 0x30000004;
            q.w[1] = (u32)&a2->e[a0->list[i]] + a2->base;
            q.w[3] = ((i + 1) * 4 + 0x18) | 0x6C040000;
            *(u128 *)p = q.q;
            p += 16;
        }
    }
    if ((c = a0->f.lo) != 0) {
        q.w[0] = ((c >> 2) + 1) | 0x30000000;
        q.w[1] = (u32)a2->e[a0->idx].x110 + a2->base;
        q.w[3] = (((a0->f.lo >> 2) + 1) << 16) | 0x6C000038;
        *(u128 *)p = q.q;
        p += 16;
    }
    q.q = 0;
    q.w[0] = 0x10000001;
    q.w[3] = 0x6C010028;
    s = a3;
    t = s.s.a & 3;
    if (t == 0) {
        t = s.s.b11 ? 0x100 : (s.s.b12 ? 0x200 : 0);
    }
    t |= ((s.s.a >> 2) & 3) << 4;
    r.w[0] = t;
    r.w[1] = a0->f.lo;
    r.w[2] = a0->f.mid;
    r.w[3] = n | (D_00222A51[0].f.b3 ? 0 : 4) | (D_00222A50[0].f.b1 ? 8 : 0);
    ((u128 *)p)[0] = q.q;
    ((u128 *)p)[1] = r.q;
    sceVu0CopyVector(a2->e[a0->idx].m, D_001F2110);
    q.q = 0;
    q.w[0] = 0x30000001;
    q.w[1] = (u32)a2->e[a0->idx].m + a2->base;
    q.w[3] = 0x6C010029;
    ((u128 *)p)[2] = q.q;
    q.q = 0;
    q.w[0] = 0x10000000;
    q.w[3] = D_00201F54 | 0x15000000;
    ((u128 *)p)[3] = q.q;
    GsPkt_Commit_1_00154A70();
}

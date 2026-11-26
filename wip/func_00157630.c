#include "common.h"
typedef union { u128 q; u64 d[2]; u32 w[4]; f32 f[4]; } Q;
typedef struct { s16 x, y; } Pt;
typedef struct { u8 pad[0x140]; Pt p[11]; } Row;
extern s32 D_00201F2C;
extern f32 D_00201E90;
extern f32 D_002F1AE0[];
extern f32 D_002F1AE4[];
extern f32 D_002F1AE8[];
extern f32 D_002F1AEC[];
extern f32 D_002F2070[];
extern Row D_002F19B0[];
extern void func_001545D0(void);
extern void func_001543E0(s32, u64);
extern void func_00154420(void);
extern Q *func_00154A80(s32);
extern void func_00154A70(void);
extern void func_00176AE0(void);
extern u64 func_0011F650(f32);
static inline s32 wd(void) { return D_00201F2C ? 0 : 0x1180; }

void func_00157630(void) {
    Q *p;
    u8 j;
    u8 i;
    s32 ii;
    s32 jj;
    s32 e;
    u8 k;
    u8 l;
    f32 f;
    u64 v;
    Q q;

    func_001545D0();
    func_001543E0(0x3F, 0xFFFFFFFF);
    func_001543E0(0x4C, 0xA0118);
    func_001543E0(0x4E, ((u64)1 << 32) | 0x3A000118);
    func_001543E0(0x47, 0x31001);
    func_001543E0(0x40, ((u64)0xDF0000 << 32) | 0x27F0000);
    func_00154420();
    p = func_00154A80(9);
    q.q = 0;
    q.w[0] = 0x10000008;
    q.w[3] = 0x50000008;
    p[0].q = q.q;
    q.d[0] = ((u64)0x708B4000 << 32) | 0x8001;
    q.d[1] = 0x53538E6;
    p[1].q = q.q;
    q.d[0] = (s64)wd() | (((u64)0xE << 32) | 0xA8028000);
    q.d[1] = 0;
    p[2].q = q.q;
    q.d[0] = 0;
    q.d[1] = 0x14;
    p[3].q = q.q;
    q.d[0] = 5;
    q.d[1] = 0;
    p[4].q = q.q;
    q.w[0] = 0;
    q.w[1] = 0;
    q.d[1] = 0;
    p[5].q = q.q;
    q.w[0] = 0x6C00;
    q.w[1] = 0x7200;
    q.w[2] = 0;
    q.w[3] = 0;
    p[6].q = q.q;
    q.w[0] = 0x2810;
    q.w[1] = 0x1C10;
    q.d[1] = 0;
    p[7].q = q.q;
    q.w[0] = 0x9400;
    q.w[1] = 0x8000;
    q.w[2] = 0;
    q.w[3] = 0;
    p[8].q = q.q;
    func_00154A70();
    func_001545D0();
    func_001543E0(0x4C, (s64)(wd() / 32) | 0xA0000);
    func_001543E0(0x4E, 0x3A000118);
    f = D_00201E90;
    v = (func_0011F650(f) << 32) | 0x27F0000;
    func_001543E0(0x40, v | (func_0011F650(448.0f - f - 1.0f) << 48));
    func_001543E0(0x47, 0x31001);
    func_001543E0(6, ((u64)6 << 32) | 0xA802A300);
    func_001543E0(0x14, 0x60);
    func_001543E0(1, 5);
    func_00154420();
    for (i = 0; i < 7; i++) {
        ii = i;
        e = ii + 2;
        for (j = 0; j < 10; j++) {
            p = func_00154A80(0xB);
            q.q = 0;
            q.w[0] = 0x1000000A;
            q.w[3] = 0x5000000A;
            p[0].q = q.q;
            q.d[0] = ((u64)0x908A4000 << 32) | 0x8001;
            q.d[1] = ((u64)5 << 32) | 0x35353531;
            p[1].q = q.q;
            q.w[0] = 128.0f * D_002F1AE0[0];
            q.w[1] = 128.0f * D_002F1AE4[0];
            q.w[2] = 128.0f * D_002F1AE8[0];
            q.w[3] = 0x80;
            p[2].q = q.q;
            p += 3;
            for (k = i; k < e; k++) {
                jj = j;
                for (l = j; l < jj + 2; l++) {
                    Pt *a = &D_002F19B0[k].p[l];
                    Pt *b = &D_002F19B0[k + 8].p[l];
                    q.w[0] = (s16)((s16)(s32)(D_002F1AEC[0] * (a->x + D_002F2070[0] * (b->x - a->x))) >> 2) + l * 10240 / 10;
                    q.w[1] = (s16)((s16)(s32)(D_002F1AEC[0] * (a->y + D_002F2070[0] * (b->y - a->y))) >> 2) + k * 3584 / 7;
                    q.d[1] = 0;
                    p[0].q = q.q;
                    q.w[0] = l * 10240 / 10 + 0x6C00;
                    q.w[1] = k * 7168 / 7 + 0x7200;
                    q.w[2] = 0;
                    q.w[3] = 0;
                    p[1].q = q.q;
                    p += 2;
                }
            }
            func_00154A70();
        }
    }
    func_00176AE0();
}


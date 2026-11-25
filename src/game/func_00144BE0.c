#include "common.h"
typedef struct { u8 pad[8]; u16 x8; u8 padA[0xE]; f32 x18; f32 p1C; f32 x20; f32 p24; f32 x28; } Arg;
extern char *D_00201FA8;
u8 *func_00165130(Arg *, s32);
s32 func_001CAC30(void);
s32 func_001CADF0(s16, Vec *, Vec *, s32);
void func_00140470(char *, Vec *);
void func_001403D0(char *, Vec *);
void func_00140360(char *, Vec *);
void func_00140440(char *, Vec *);

void func_00144BE0(Arg *a0) {
    char *pl = *(char **)(D_00201FA8 + 0x154);
    u16 n = a0->x8;
    u8 *out = func_00165130(a0, 1);
    f32 f22 = a0->x18;
    f32 f21 = a0->x20;
    f32 f20 = a0->x28;
    s8 r = func_001CAC30();
    if (r == -1) {
        Vec p;
        Vec d;
        Vec q;
        func_00140470(pl, &p);
        func_001403D0(pl, &d);
        p.x += d.x * f22;
        p.z += d.z * f22;
        p.y += f21;
        func_00140360(pl, &d);
        p.x += d.x * f20;
        p.z += d.z * f20;
        func_00140440(pl, &q);
        r = func_001CADF0(n, &p, &q, 0);
    }
    if (r == 0) {
        *out = 0;
    } else {
        *out = 1;
    }
}

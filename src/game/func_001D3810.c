#include "common.h"
typedef struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:1; u8 b6:1; u8 b7:1; } B8;
typedef struct { u16 x0; u16 x2; u16 x4; u16 x6; s32 x8; s32 xC; s32 x10; s32 x14; u16 x18; u16 x1A; } E;
extern s8 D_001FDE10[];
void func_00163C80(s8 *, Vec *);
void func_00102A60(Vec *, void *);
s32 func_00131560(s32, s32, s8 *);
s8 *func_00169B50(s32, s32, s32, s32);
void func_00167740(s8 *, void *);
void func_00146140(Vec *, f32, f32);
void func_001256E0(s8 *, s8 *, s32);
s32 func_001672A0(s8 *);
void func_001672B0(s8 *, s32);
s32 func_001675D0(s8 *);
void func_00167600(s8 *, s32);
void func_001D3A90(s8 *, E *, s32, s32, s32, s32);

void func_001D3810(s8 *a0, s32 id, E *e, s8 *a3, s32 t0, s32 t1, s32 t2) {
    Vec V;
    Vec M2[4];
    s8 str[0x100];
    Vec M1[4];
    s32 i;
    E *p;
    s32 name;
    s32 mode;
    s8 *h;
    if (e->x0 == id) {
        for (i = 0, p = e; i < 4; i++, p = (E *)((s8 *)p + 4)) {
            if (p->x18 != 0) {
                if (((B8 *)(a0 + 0x114))->b5) {
                    func_00163C80(a0, M1);
                    func_00102A60(&V, &M1[3]);
                } else {
                    func_00102A60(&V, a0);
                }
                *(s32 *)(a0 + 0x110) = func_00131560(p->x18, p->x1A, a0 + 0x100);
            }
        }
        switch (e->x4) {
        case 0:
            break;
        case 1:
            name = e->x8;
            mode = e->xC;
            if (name != 0) {
                h = func_00169B50(name, 0, 0, 0);
                if (h != 0) {
                    switch (mode) {
                    case 0:
                        func_00167740(h, a3);
                        break;
                    case 1:
                        func_00146140(M2, *(f32 *)(a3 + 0x20), *(f32 *)(a3 + 0x28));
                        func_00102A60(&M2[3], a3 + 0x30);
                        func_00167740(h, M2);
                        break;
                    default:
                        func_001256E0(str, D_001FDE10, name);
                        break;
                    }
                    if (((B8 *)(*(s8 **)(a0 + 0x90) + 0x18A))->b1) {
                        func_001672B0(h, func_001672A0(*(s8 **)(a0 + 0x90)));
                    }
                    func_00167600(h, func_001675D0(*(s8 **)(a0 + 0x90)));
                }
            }
            break;
        case 2:
            func_001D3A90(a0, e, t0, t1, t2, 0);
            break;
        }
        if (e->x4 != 2 && 0 < e->x14) {
            func_001D3A90(a0, e, t0, t1, t2, 3);
        }
    }
}

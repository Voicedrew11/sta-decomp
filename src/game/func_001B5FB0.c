#include "m2c.h"
typedef struct { u8 pad[0x18]; s16 x18; u8 pad1A[6]; u8 x20; u8 pad21[7]; } E28;
typedef struct { s32 a; s32 b; } E8;
void func_00102A60(f32 *, s8 *);
s16 func_001A9900(s32, u32, f32 *, f32 *);
s32 func_001A9BE0(s32, s16);
void func_001AEC00(s32, s16, f32 *, f32 *, f32 *);
s32 func_001AF150(s32, E28 *, u16, f32 *);
s32 func_001CC0C0(s16, s32);
s32 func_001AA740(void);
s32 func_0015C9E0(void);

void func_001B5FB0(s8 *arg0, s32 arg1) {
    f32 b0[4];
    f32 a0[4];
    f32 v90[4];
    u32 i;
    E8 *f;
    s32 off1;
    s32 off2;
    E28 *e;
    s32 id;
    s16 r;

    func_00102A60(b0, arg0 + 0x10);
    i = 0;
    if (i < *(u16 *)(arg0 + 0x72)) {
        off1 = 0;
        off2 = 0;
        do {
            e = (E28 *)(*(s8 **)(arg0 + 0x140) + off1);
            f = (E8 *)(*(s8 **)(arg0 + 0x184) + off2);
            id = e->x18;
            if ((!(e->x20 & 1) || func_001AA740() != 0) && func_001A9BE0(*(s32 *)arg0, i) == 0 &&
                func_001CC0C0(id, 0) != 0) {
                f->b = func_0015C9E0();
                f->a = func_001AF150(arg1, e, i, b0);
            }
            i++;
            off1 += 0x28;
            off2 += 8;
        } while (i < *(u16 *)(arg0 + 0x72));
    }
    for (i = 0; i < 0x10; i++) {
        r = func_001A9900(*(s32 *)arg0, i, a0, v90);
        if (r > 0 && func_001CC0C0(r, 0) != 0) {
            func_001AEC00(arg1, r, a0, v90, b0);
        }
    }
}

#include "m2c.h"
typedef struct { f32 v[9]; } F9;
s8 *func_001B72F0(void);
s8 *func_001B7300(s8 *, s32);
s32 func_0013EE30(s8 *);
extern f32 D_00222A48[];

void func_001374E0(s8 *arg0, s8 *arg1, s8 *arg2, s8 *arg3) {
    s8 *v;
    s32 id;
    f32 k;

    if (arg0 == NULL) return;
    if (arg1 == NULL) {
        v = func_001B72F0();
    } else {
        id = -1;
        if (func_0013EE30(arg0)) {
            if (arg2 != NULL) id = M2C_FIELD(arg2, s8 *, 0x25);
            else if (arg3 != NULL) id = M2C_FIELD(arg3, s8 *, 0x22);
        } else if (arg2 != NULL && ((u64)((s64)M2C_FIELD(arg2, u8 *, 0x28) << 58) >> 63)) {
            id = M2C_FIELD(arg2, s8 *, 0x25);
        } else if (arg3 != NULL && ((u64)((s64)M2C_FIELD(arg3, u8 *, 0x24) << 58) >> 63)) {
            id = M2C_FIELD(arg3, s8 *, 0x22);
        }
        v = func_001B7300(arg1, id);
        if (v == NULL) v = func_001B72F0();
    }
    if (v != NULL) {
        if ((M2C_FIELD(arg0, u8 *, 0x5B3) & 3) < 3) {
            M2C_FIELD(arg0, f32 *, 0x550) = M2C_FIELD(v, f32 *, 0x10);
            M2C_FIELD(arg0, f32 *, 0x554) = M2C_FIELD(v, f32 *, 0x14);
            M2C_FIELD(arg0, f32 *, 0x558) = M2C_FIELD(v, f32 *, 0x18);
            M2C_FIELD(arg0, f32 *, 0x55C) = M2C_FIELD(v, f32 *, 0x1C);
            M2C_FIELD(arg0, f32 *, 0x560) = M2C_FIELD(v, f32 *, 0x20);
            M2C_FIELD(arg0, f32 *, 0x564) = M2C_FIELD(v, f32 *, 0x24);
            M2C_FIELD(arg0, f32 *, 0x568) = M2C_FIELD(v, f32 *, 0x28);
            M2C_FIELD(arg0, f32 *, 0x56C) = M2C_FIELD(v, f32 *, 0x2C);
            M2C_FIELD(arg0, f32 *, 0x570) = M2C_FIELD(v, f32 *, 0x30);

        } else {
            M2C_FIELD(arg0, f32 *, 0x550) = M2C_FIELD(arg0, f32 *, 0x550) + D_00222A48[0] * (M2C_FIELD(v, f32 *, 0x10) - M2C_FIELD(arg0, f32 *, 0x550));
            M2C_FIELD(arg0, f32 *, 0x554) = M2C_FIELD(arg0, f32 *, 0x554) + D_00222A48[0] * (M2C_FIELD(v, f32 *, 0x14) - M2C_FIELD(arg0, f32 *, 0x554));
            M2C_FIELD(arg0, f32 *, 0x558) = M2C_FIELD(arg0, f32 *, 0x558) + D_00222A48[0] * (M2C_FIELD(v, f32 *, 0x18) - M2C_FIELD(arg0, f32 *, 0x558));
            M2C_FIELD(arg0, f32 *, 0x55C) = M2C_FIELD(arg0, f32 *, 0x55C) + D_00222A48[0] * (M2C_FIELD(v, f32 *, 0x1C) - M2C_FIELD(arg0, f32 *, 0x55C));
            M2C_FIELD(arg0, f32 *, 0x560) = M2C_FIELD(arg0, f32 *, 0x560) + D_00222A48[0] * (M2C_FIELD(v, f32 *, 0x20) - M2C_FIELD(arg0, f32 *, 0x560));
            M2C_FIELD(arg0, f32 *, 0x564) = M2C_FIELD(arg0, f32 *, 0x564) + D_00222A48[0] * (M2C_FIELD(v, f32 *, 0x24) - M2C_FIELD(arg0, f32 *, 0x564));
            M2C_FIELD(arg0, f32 *, 0x568) = M2C_FIELD(arg0, f32 *, 0x568) + D_00222A48[0] * (M2C_FIELD(v, f32 *, 0x28) - M2C_FIELD(arg0, f32 *, 0x568));
            M2C_FIELD(arg0, f32 *, 0x56C) = M2C_FIELD(arg0, f32 *, 0x56C) + D_00222A48[0] * (M2C_FIELD(v, f32 *, 0x2C) - M2C_FIELD(arg0, f32 *, 0x56C));
            M2C_FIELD(arg0, f32 *, 0x570) = M2C_FIELD(arg0, f32 *, 0x570) + D_00222A48[0] * (M2C_FIELD(v, f32 *, 0x30) - M2C_FIELD(arg0, f32 *, 0x570));

        }
    }
}

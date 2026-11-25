#include "common.h"
typedef struct { u8 p:4; u8 v:3; } BF30;
typedef struct { u8 p:1; u8 v:1; } BF31;
s32 func_0013DCC0(void);
s32 func_0013D6B0(void);
s32 func_0013EEE0(s8 *);
s32 func_0013EB30(s8 *);
s32 func_0013EB00(s8 *);
u32 func_0013E750(s8 *);
void func_0013E280(s8 *, s32);
s8 *func_0013E060(s8 *);
void func_0013DE70(s8 *, s8 *, u16 *);
s32 func_001AB2C0(s8 *, u16 *, s32);
s32 func_001AB500(s8 *, u16 *);
void func_00133FD0(s8 *, s8 *, s8 *);
u16 func_0013F710(s8 *, s32);
u32 func_0013E7B0(s8 *);
u16 func_0013F700(s8 *);
void func_0013CA40(s8 *, u8);
void func_0013C850(s8 *);
void func_0013EF80(s8 *, u8);
s8 *func_0013DCA0(s8 *, u8);
u16 func_0013F5C0(s8 *, u8, s32);
u32 func_0013EC80(s8 *, u8);
void func_0013F210(s8 *, u8, s32);
void func_0013C950(s8 *, u8, u8);
u32 func_0013EC60(s8 *, u8);
void func_0013EC30(s8 *, s32);
void func_00141DA0(s8 *);
s32 func_0013D500(s32);
f32 *func_0013FFA0(s8 *);
s8 func_0013E260(s8 *);
void func_001BC320(f32 *, s32);
u16 func_0013F5A0(s8 *, u8);
f32 *func_0013F030(s8 *, u8);

s32 func_00135E90(s8 *a0, s32 a1, s8 *a2, u8 a3, s32 *out) {
    u8 who;
    u8 lv;
    u16 buf[8];
    u16 buf2[8];
    s8 *t;
    s32 dmg;
    s32 neg;
    u16 hp;
    s32 n;
    u8 done;
    f32 *v;

    who = func_0013DCC0();
    lv = ((BF30 *)(a2 + 0x30))->v;
    if (out != NULL) *out = 0;
    if (func_0013D6B0()) return 0;
    if (func_0013EEE0(a0)) return 0;
    if (func_0013EB30(a0)) return 0;
    if (func_0013EB00(a0)) return 0;
    if ((u8)func_0013E750(a0) == 2) who = 0xFF;
    if ((u8)func_0013E750(a0) == 1) who = 0xFF;
    func_0013E280(a0, (s8)lv);
    if (who == 0xFF) {
        t = func_0013E060(a0);
        func_0013DE70(a0, t, buf);
        if (a3 == 0) {
            dmg = func_001AB2C0(a2, buf, ((BF31 *)(a2 + 0x31))->v);
        } else {
            dmg = func_001AB500(a2, buf);
        }
        func_00133FD0(a0, a2, t);
        hp = func_0013F710(a0, -dmg);
        if (func_0013E7B0(a0)) {
            hp = func_0013F710(a0, -func_0013F700(a0) - 1);
        }
        if (hp > 0) {
            done = 1;
            func_0013CA40(a0, 0xFF);
        } else {
            done = 1;
            func_0013C850(a0);
            func_0013EF80(a0, a3);
        }
    } else {
        func_0013DE70(a0, func_0013DCA0(a0, who) + 0x30, buf2);
        if (a3 == 0) {
            dmg = func_001AB2C0(a2, buf2, ((BF31 *)(a2 + 0x31))->v);
        } else {
            dmg = func_001AB500(a2, buf2);
        }
        func_00133FD0(a0, a2, func_0013E060(a0));
        neg = -dmg;
        hp = func_0013F710(a0, neg);
        if (func_0013E7B0(a0)) {
            hp = func_0013F710(a0, -func_0013F700(a0) - 1);
        }
        if (func_0013F5C0(a0, who, neg) > 0) {
            u16 h = hp;
            done = 1;
            if (h > 0) {
                func_0013CA40(a0, who);
            } else {
                func_0013C850(a0);
                func_0013EF80(a0, a3);
            }
        } else if (func_0013EC80(a0, who)) {
            done = 0;
            func_0013F210(a0, who, 0);
            func_0013C950(a0, who, lv);
            func_0013EF80(a0, a3);
            if (func_0013EC60(a0, who)) {
                func_0013EC30(a0, 1);
                func_00141DA0(a0);
            }
        } else if (hp > 0) {
            done = 0;
            func_0013F210(a0, who, 0);
            func_0013C950(a0, who, lv);
            if (func_0013EC60(a0, who)) {
                func_0013EC30(a0, 1);
                func_00141DA0(a0);
            }
        } else {
            done = 1;
            func_0013C850(a0);
            func_0013EF80(a0, a3);
        }
    }
    if (done && dmg > 0) {
        if (who == 0xFF) {
            n = dmg * 50 / func_0013F700(a0) + 0x19;
            if (n > 0x4B) n = 0x4B;
            if ((u32)func_0013D500(0x63) < n) {
                v = func_0013FFA0(a0);
                func_001BC320(v, func_0013E260(a0));
            }
        } else {
            n = dmg * 50 / func_0013F5A0(a0, who) + 0x19;
            if (n > 0x4B) n = 0x4B;
            if ((u32)func_0013D500(0x63) < n) {
                v = func_0013F030(a0, who);
                func_001BC320(v, func_0013E260(a0));
            }
        }
    }
    if (out != NULL) *out = dmg;
    return 1;
}

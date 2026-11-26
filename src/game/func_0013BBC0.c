#include "actor.h"
typedef struct { u8 lo:2; u8 rest:6; } B2;
typedef struct { u8 pad[0x5B3]; B2 f; } A5;
s32 func_0012C020(void);
void func_0012C030(s32);
Actor *func_001A5460(s32 *);
void func_001A5440(Actor *);
void func_001A7E60(Actor *);
s32 func_0013EA40(Actor *);
void func_001411F0(Actor *);
void func_0013D680(s32);
s32 func_0013D690(void);
void func_0013D6A0(s32);
s32 func_0013FF90(Actor *);
void func_001C8EA0(s32, f32);
u64 func_001C9AE0(void);
s32 func_0013EE30(Actor *);
void func_0013DB80(Actor *, f32);
void func_0013DB10(Actor *, f32);
void func_0013DA20(Actor *, f32);
void func_0013D8A0(Actor *, f32);
void func_0013D760(Actor *, f32);
void func_0013DA90(Actor *, f32);
void func_0013E640(Actor *, s32);
s32 func_0013F8E0(Actor *);
void func_0013F8C0(Actor *, s32);
u8 func_0013F8B0(Actor *);
void func_0013B4F0(Actor *, f32, s32);
void func_0013B220(Actor *, f32, s32);
void func_00171610(s32);
void sceVu0CopyVector(s32, s8 *);
extern u8 D_00201F14;

void func_0013BBC0(f32 dt) {
    s32 it1;
    s32 it3;
    s32 it4;
    s32 it5;
    s32 it6;
    s32 it7;
    s32 it2;
    Actor *sel;
    u8 flag;
    Actor *o;
    u8 cnt;

    flag = func_0012C020();
    it1 = 0;
    o = func_001A5460(&it1);
    if (o != NULL) {
        do {
            func_001A5440(o);
            func_001A7E60(o);
            o = func_001A5460(&it1);
        } while (o != NULL);
    }
    it2 = 0;
    sel = NULL;
    o = func_001A5460(&it2);
    if (o != NULL) {
        do {
            func_001A5440(o);
            if (!func_0013EA40(o) == 0) {
                func_001411F0(o);
                sel = o;
                break;
            }
            o = func_001A5460(&it2);
        } while (o != NULL);
    }
    if (sel != NULL) {
        func_0013D680(1);
        flag = 1;
        func_0012C030(1);
        func_001C8EA0(func_0013FF90(sel), 0.9f);
    } else if (func_0013D690()) {
        flag = 0;
        func_0012C030(0);
        func_0013D680(0);
    }
    if (flag || func_001C9AE0()) {
        func_0013D6A0(1);
    } else {
        func_0013D6A0(0);
    }
    if (sel != NULL || (!flag && !func_001C9AE0())) {
        it3 = 0;
        cnt = 0;
        o = func_001A5460(&it3);
        if (sel != NULL) o = sel;
        while (o != NULL) {
            func_001A5440(o);
            if (!func_0013EE30(o)) {
                func_0013DB80(o, dt);
                func_0013DB10(o, dt);
                func_0013DA20(o, dt);
                func_0013D8A0(o, dt);
                func_0013D760(o, dt);
                func_0013DA90(o, dt);
                if (D_00201F14 == cnt % 8) {
                    func_0013E640(o, 1);
                } else {
                    func_0013E640(o, 0);
                }
                func_0013F8C0(o, func_0013F8E0(o));
            }
            cnt++;
            o = func_001A5460(&it3);
            if (sel != NULL) break;
        }
        D_00201F14++;
        if (D_00201F14 >= 8) {
            D_00201F14 = 0;
        }
    }
    if (flag || func_001C9AE0()) {
        it4 = 0;
        o = func_001A5460(&it4);
        if (o != NULL) {
            do {
                func_001A5440(o);
                if (func_0013EE30(o) || o == sel) {
                    func_0013B4F0(o, dt, 0);
                } else if (!func_0013EE30(o)) {
                    func_00171610(*(s32 *)(o->unk518 + 0x1A4));
                }
                o = func_001A5460(&it4);
            } while (o != NULL);
        }
    } else {
        Actor *p;
        s32 k;
        it5 = 0;
        p = func_001A5460(&it5);
        if (p != NULL) {
            do {
                k = func_0013F8B0(p);
                func_001A5440(p);
                func_0013B4F0(p, dt, k);
                p = func_001A5460(&it5);
            } while (p != NULL);
        }
    }
    if (flag || func_001C9AE0()) {
        it6 = 0;
        o = func_001A5460(&it6);
        if (o != NULL) {
            do {
                func_001A5440(o);
                if (func_0013EE30(o) || o == sel) {
                    func_0013B220(o, dt, 0);
                } else {
                    s8 *s = o->unk518 + 0x180;
                    if (!func_0013EE30(o)) {
                        sceVu0CopyVector(*(s32 *)(s + 0x18), s + 0x40);
                        sceVu0CopyVector(*(s32 *)(s + 0x18) + 0x40, s + 0x50);
                    }
                }
                o = func_001A5460(&it6);
            } while (o != NULL);
        }
    } else {
        s32 k;
        it7 = 0;
        o = func_001A5460(&it7);
        if (o != NULL) {
            do {
                k = func_0013F8B0(o);
                func_001A5440(o);
                func_0013B220(o, dt, k);
                if ((u8)k == 0) {
                    { A5 *a = (A5 *)o; if (a->f.lo < 3) a->f.lo = a->f.lo + 1; }
                }
                o = func_001A5460(&it7);
            } while (o != NULL);
        }
    }
}

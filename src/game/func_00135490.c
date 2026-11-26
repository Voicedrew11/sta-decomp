#include "common.h"
typedef struct { u16 v[4]; } Ids __attribute__((aligned(8)));
extern Ids D_00201C40;
f32 sqrtf(f32);
u8 func_0013E240(s8 *);
u8 func_00135990(s8 *, f32 *, f32 *, f32 *);
void func_0013EA80(s8 *, s32);
u16 func_0013E110(s8 *);
s8 *func_001A5460(s32 *);
s32 func_0013EE30(s8 *);
s32 func_0013EEE0(s8 *);
s32 func_0013E220(s8 *);
s8 func_0013E290(s8 *);
void func_00140470(s8 *, s8 *);
void func_00140440(s8 *, s8 *);
Vec *func_00140460(s8 *);
Vec *func_00145730(void);
void func_001029E8(Vec *, Vec *, Vec *);
f32 func_00102848(Vec *, Vec *);
void func_001403D0(s8 *, Vec *);

u8 func_00135490(s8 *a, f32 *pl, f32 *pc, f32 *py) {
    s32 it;
    s32 it2;
    Ids ids;
    Vec d;
    Vec d2;
    Vec m;
    u8 t;
    u8 i;
    s8 *e;
    s8 *best;
    u16 id;
    u16 id2;
    s8 *e2;
    u8 k;
    f32 min;
    f32 dist;
    f32 len;
    f32 cs;
    f32 dy;

    t = func_0013E240(a);
    if (t == 0) return func_00135990(a, pl, pc, py);
    best = NULL;
    func_0013EA80(a, 0);
    if (t == 1) {
        id = func_0013E110(a);
        ids = D_00201C40;
        switch (id) {
        case 0x1068:
        case 0x1069:
            ids.v[0] = 0x106C;
            ids.v[1] = 0x106D;
            break;
        case 0x106A:
        case 0x106B:
            ids.v[0] = 0x106D;
            ids.v[1] = 0x106C;
            break;
        case 0x106C:
            ids.v[0] = 0x106B;
            ids.v[1] = 0x1068;
            ids.v[2] = 0x1069;
            ids.v[3] = 0x106A;
            break;
        case 0x106D:
            ids.v[0] = 0x106B;
            ids.v[1] = 0x106A;
            ids.v[2] = 0x1069;
            ids.v[3] = 0x1068;
            break;
        case 0x1078:
            ids.v[0] = 0x1079;
            break;
        case 0x1079:
            ids.v[0] = 0x1078;
            break;
        }
        it = 0;
        for (e = func_001A5460(&it); e != NULL; e = func_001A5460(&it)) {
            if (!func_0013EE30(e) && !func_0013EEE0(e)) {
                id2 = func_0013E110(e);
                for (i = 0; i < 4; i++) {
                    if (id2 == ids.v[i]) {
                        best = e;
                        func_00140470(e, a + 0x680);
                        func_00140440(e, a + 0x690);
                        break;
                    }
                }
            }
            if (best) break;
        }
    } else if (t == 2) {
        min = 4000000.0f;
        it2 = 0;
        for (e2 = func_001A5460(&it2); e2 != NULL; e2 = func_001A5460(&it2)) {
            if (!func_0013EE30(e2) && !func_0013EEE0(e2)) {
                k = func_0013E220(e2);
                if (k >= 0x33 && k < 0x36 && func_0013E290(e2) == 0xF) {
                    func_001029E8(&d, func_00140460(e2), func_00140460(a));
                    dist = func_00102848(&d, &d);
                    if (dist < min) {
                        min = dist;
                        best = e2;
                        func_00140470(e2, a + 0x680);
                        func_00140440(e2, a + 0x690);
                    }
                }
            }
        }
    }
    if (best != NULL) {
    func_001029E8(&d2, func_00140460(best), func_00140460(a));
    sqrtf(func_00102848(&d2, &d2));
    dy = d2.y;
    dy = dy < 0.0f ? -dy : dy;
    *(s32 *)&d2.y = 0;
    len = sqrtf(func_00102848(&d2, &d2));
    if (len > 0.0f) {
        d2.x /= len;
        d2.y /= len;
        d2.z /= len;
    }
    func_001403D0(a, &m);
    cs = func_00102848(&d2, &m);
    if (pl) *pl = len;
    if (pc) *pc = cs;
    if (py) *py = dy;
    if (t == 1) {
        dy = func_00140460(a)->y - func_00145730()->y;
        if (dy < -500.0f || !(dy <= 500.0f)) return 0;
    }
    return 1;
    }
    return func_00135990(a, pl, pc, py);
}

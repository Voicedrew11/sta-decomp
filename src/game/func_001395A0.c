#include "common.h"
typedef struct { u8 pad[0xE]; u16 xE; } E;
typedef struct { s32 v[12]; } T30;
typedef struct { u8 pad[0xE]; u16 xE; } E10;
extern Vec D_001F1C70;
extern s16 D_001F1C30[];
extern s16 D_001F1C50[];
extern s16 D_001F1C60[];
s8 *func_001A5430(void);
s32 func_001A9410(void);
u8 func_0013E5E0(s8 *);
s8 func_0013E290(s8 *);
s8 func_0013E260(s8 *);
s8 func_0013E270(s8 *);
void func_00173FD0(Vec *, Vec *, Vec *, Vec *);
Vec *func_00140460(s8 *);
void sceVu0AddVector(Vec *, Vec *, Vec *);
Vec *func_00145730(void);
void sceVu0SubVector(Vec *, Vec *, Vec *);
f32 sceVu0InnerProduct(Vec *, Vec *);
f32 sqrtf(f32);
void func_001C8F30(f32, f32, f32, f32);
void func_0015FE20(f32, f32, f32, f32, f32);
void func_0015FD90(f32, f32, f32, f32, f32);
void memcpy(void *, void *, s32);
s8 *func_001D1F20(s32, s8 *, s32, f32, u8, E *, s32, s32);
void func_00167600(s8 *, s8 *);

void func_001395A0(f32 f, s32 a0, s32 a1, u8 a2, E *e, s32 *tbl, s32 t1) {
    s8 *a;
    s32 *base;
    s32 id;
    s8 *obj;
    s16 k;
    s8 c;
    f32 d;

    if (t1 == 0) return;
    a = func_001A5430();
    base = &tbl[e->xE];
    id = base[0];
    obj = 0;
    if (!(u8)func_001A9410() && id >= 0x1F2 && id <= 0x24B) return;
    if (id == 0x1D4) {
        t1 = base[1];
        {
        Vec v;
        f32 m[12];
        Vec p = {0};
        Vec r = {0};
        Vec s;
        Vec w;
        Vec *pv;
        Vec *q;
        s = D_001F1C70;
        p.x = ((f32 *)base)[2];
        p.y = ((f32 *)base)[3];
        p.z = ((f32 *)base)[4];
        func_00173FD0((Vec *)m, &p, &r, &s);
        base = (s32 *)&v;
        sceVu0AddVector((Vec *)base, (Vec *)base, func_00140460(a));
        switch (t1) {
        case 1:
            func_001C8F30(10.0f, 30.0f, 0.9f, 10.0f);
            func_0015FE20(1.0f, 5.0f, 0.0f, 1.0f, 16.0f);
            func_0015FD90(1.0f, 50.0f, 0.0f, 1.0f, 16.0f);
            break;
        case 2:
            func_001C8F30(10.0f, 30.0f, 0.9f, 10.0f);
            func_0015FE20(1.0f, 5.0f, 0.0f, 1.0f, 16.0f);
            func_0015FD90(1.0f, 50.0f, 0.0f, 1.0f, 16.0f);
            break;
        case 3:
            func_001C8F30(3.0f, 3.0f, 1.0f, 40.0f);
            func_0015FE20(50.0f, 10.0f, 0.0f, 0.5f, 40.0f);
            func_0015FD90(50.0f, 10.0f, 0.0f, 0.5f, 40.0f);
            break;
        case 4:
            func_001C8F30(10.0f, 30.0f, 0.9f, 10.0f);
            func_0015FE20(1.0f, 5.0f, 0.0f, 1.0f, 16.0f);
            func_0015FD90(1.0f, 50.0f, 0.0f, 1.0f, 16.0f);
            break;
        case 100:
            sceVu0SubVector(&w, func_00145730(), (Vec *)base);
            d = sqrtf(sceVu0InnerProduct(&w, &w));
            if (d < 800.0f) {
                func_001C8F30(10.0f, 30.0f, 1.0f, 10.0f);
                func_0015FE20(1.0f, 10.0f, 0.0f, 1.0f, 16.0f);
                func_0015FD90(1.0f, 50.0f, 0.0f, 1.0f, 16.0f);
            } else if (d < 1600.0f) {
                d -= 800.0f;
                d /= 800.0f;
                f = 1.0f - d;
                func_001C8F30(10.0f, 30.0f, f, 10.0f);
                func_0015FE20(1.0f, 10.0f, 0.0f, f, 16.0f);
                func_0015FD90(1.0f, 50.0f, 0.0f, f, 16.0f);
            }
            break;
        default:
            func_001C8F30(10.0f, 30.0f, 0.9f, 10.0f);
            func_0015FE20(1.0f, 5.0f, 0.0f, 1.0f, 16.0f);
            func_0015FD90(1.0f, 50.0f, 0.0f, 1.0f, 16.0f);
            break;
        }
        }
        return;
    }
    if ((func_0013E5E0(a) & 8) && id >= 100 && id <= 0x102) return;
    if (id == 0x1E0 || id == 0x1F2 || id == 0x1F3) {
        k = -1;
        if (id == 0x1E0) {
            c = func_0013E290(a);
            if (c >= 0 && D_001F1C30[c] >= 0) k = D_001F1C30[c];
        } else if (id == 0x1F3) {
            id = func_0013E260(a);
            if (id >= 0) {
                c = func_0013E270(a);
                if (c >= 0 && D_001F1C50[c] >= 0) k = D_001F1C50[c] + id * 10;
            }
        } else if (id == 0x1F2) {
            id = func_0013E260(a);
            if (id >= 0) {
                c = func_0013E270(a);
                if (c >= 0 && D_001F1C60[c] >= 0) k = D_001F1C60[c] + id * 10;
            }
        }
        if (k >= 0) {
            T30 g;
            E10 h;
            memcpy(&g, &tbl[e->xE], 0x30);
            memcpy(&h, e, 0x10);
            g.v[0] = k;
            h.xE = 0;
            obj = func_001D1F20(a0, a + 0x580, a1, f, a2, (E *)&h, (s32)g.v, t1);
        }
    } else {
        obj = func_001D1F20(a0, a + 0x580, a1, f, a2, e, (s32)tbl, t1);
    }
    if (obj) func_00167600(obj, a);
}


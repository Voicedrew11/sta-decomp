#include "m2c.h"
typedef struct { f32 m[4]; f32 x; f32 y; } S;
typedef struct { u8 r, g, b, a; } Col;
typedef struct { u8 a:3; u8 b:5; } BF;
typedef struct { f32 x; f32 y; BF f8; u8 pad9[0xB]; f32 x14; u8 pad18[8]; f32 x20; f32 x24; u8 pad28[8]; } T;
typedef struct {
    u8 pad0[0x10];
    u8 x10[0x18];
    s32 x28;
    u8 x2C;
    u8 x2D;
    u8 x2E;
    u8 x2F;
    f32 x30;
    f32 x34;
    f32 x38;
    f32 x3C;
} O;
void func_00181680(s32, void *, void *, void *, S *, u32);
void sprintf(char *, char *, ...);
u32 strlen(void *);
void func_00187A90(void *, void *, u64);
s32 func_00188010(void *, Col);
extern S D_001F26D0 __attribute__((aligned(16)));
extern char D_0048CE40[];
extern char D_001FCB08[];
extern char D_001FCB18[];
extern char D_001FCB28[];
extern char D_001FCB30[];
extern s32 D_0020207C;
extern s32 D_00202080;

static inline void draw(char *s, f32 x, f32 y, Col *c) {
    T t;
    if (s) {
        func_00187A90(&t, s, strlen(s));
        t.f8.a = 0;
        t.x24 = 1.0f;
        t.x20 = 0.9f;
        t.x14 = 4096.0f;
        t.x = x;
        t.y = y;
        func_00188010(&t, *c);
    }
}

void func_00185740(O *o, s32 a1, u32 mode, s16 *a3) {
    Col c8;
    Col cb;
    Col ca;
    Col c9;
    f32 x;
    f32 y;
    if (mode < 200) {
        S buf __attribute__((aligned(16)));
        buf = D_001F26D0;
        buf.x = o->x30;
        buf.y = o->x34;
        func_00181680(o->x28, o, o->x10, &o->x2C, &buf, mode);
        return;
    }
    switch (mode) {
    case 200:
        *(u32 *)&c8 = 0x80808080;
        sprintf(D_0048CE40, D_001FCB08, a3[2], a3[0]);
        *(f32 *)((u8 *)o + 0x38) += 4.0f;
        x = o->x38;
        y = o->x3C;
        draw(D_0048CE40, x, y, &c8);
        break;
    case 201:
        *(u32 *)&c9 = 0x80808080;
        sprintf(D_0048CE40, D_001FCB18, a3[3], a3[1]);
        x = o->x38;
        y = o->x3C;
        draw(D_0048CE40, x, y, &c9);
        break;
    case 202:
        if (D_0020207C == 0) break;
        if (D_0020207C < 0) {
            *(u32 *)&ca = 0x80404080;
            sprintf(D_0048CE40, D_001FCB28);
        } else {
            *(u32 *)&ca = 0x80804040;
            sprintf(D_0048CE40, D_001FCB30);
        }
        x = o->x38 + 10.0f;
        y = o->x3C;
        draw(D_0048CE40, x, y, &ca);
        break;
    case 203:
        if (D_00202080 == 0) break;
        if (D_00202080 < 0) {
            *(u32 *)&cb = 0x80404080;
            sprintf(D_0048CE40, D_001FCB28);
        } else {
            *(u32 *)&cb = 0x80804040;
            sprintf(D_0048CE40, D_001FCB30);
        }
        x = o->x38 + 10.0f;
        y = o->x3C;
        draw(D_0048CE40, x, y, &cb);
        break;
    }
}

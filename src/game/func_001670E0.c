#include "m2c.h"
typedef struct { u8 t : 3; u8 r : 5; } TB;
typedef struct { u8 pad[0x10]; TB f; } P;
typedef struct { u8 pad[0x10]; s32 h; u8 pad2[0x80 - 0x14]; } Sub;
typedef struct { u8 b0 : 1; u8 b1 : 1; u8 b2 : 1; u8 b3 : 1; u8 b4 : 1; u8 b5 : 1; u8 b6 : 1; u8 b7 : 1; } B8;
typedef struct { u16 lo : 7; u16 n : 8; u16 hi : 1; } H;
typedef struct {
    u8 pad[0x188];
    union { B8 b; H h; } f188;
    B8 f18A;
    u8 pad2[0x210 - 0x18B];
    P *arr[0x18];
    Sub sub[8];
} O;
void func_00177570(s32);

void func_001670E0(O *o) {
    u32 n;
    u32 i;
    Sub *s;

    if (o->f188.b.b0) {
        if (!o->f188.b.b4) {
            n = o->f188.h.n;
            for (i = 1; i < n; i++) {
                s = &o->sub[i];
                switch (o->arr[i]->f.t) {
                case 1:
                    if (s->h) {
                        func_00177570(s->h);
                        s->h = 0;
                    }
                    break;
                case 2:
                    break;
                }
            }
        }
        o->f188.b.b0 = 0;
        o->f188.b.b1 = 0;
        o->f188.b.b3 = 0;
        o->f188.b.b4 = 0;
        o->f18A.b0 = 0;
    }
}

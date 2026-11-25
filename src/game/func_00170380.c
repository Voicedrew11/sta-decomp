#include "common.h"
typedef struct { s32 a; s32 b; s32 c8; s32 c; } H;
typedef struct Ch {
    s32 x0;
    s32 x4;
    u32 type : 8;
    u32 off : 24;
    u16 xC;
    u16 xE;
    H h;
} Ch;
typedef struct { u8 a:3; u8 b3:1; u8 b4:1; u8 b5:1; u8 b6:1; u8 b7:1; } Bits;
typedef struct {
    Vec v;
    s32 *x10;
    u16 x14, x16, x18, x1A, x1C, x1E;
    u16 x20, x22;
    s32 x24;
    s32 x28;
    s32 x2C;
    u8 pad30[0xC];
    union { s32 w; Bits f; } x3C;
} Obj;
typedef struct { s32 x0, x4, x8, xC; } E16;
typedef struct { s32 x0; u16 x4; u16 x6; } E8;
typedef struct { s32 x0, x4, x8, xC; s32 x10[8]; s32 x30[8]; } E50;
#define DATA(h) ((u8 *)((s32)(h) + 0x10) + (((h)->c + 15) & ~15))
extern volatile s32 D_0042D880[];
extern volatile s32 D_0042D884[];
extern volatile s32 D_0042D888[];
extern volatile s32 D_0042D88C[];
extern volatile s32 D_0042D890[];
extern volatile s32 D_0042D894[];
extern volatile s32 D_0042D898[];
extern E16 * volatile D_0042D89C[];
extern E8 * volatile D_0042D8A0[];
extern s32 * volatile D_0042D8A4[];
extern E50 * volatile D_0042D8A8[];
extern s32 * volatile D_0042D8AC[];
extern E8 * volatile D_0042D8B0[];
extern volatile s32 D_0042D8B4[];
extern volatile s32 D_0042D8B8[];
void func_00102A60(Vec *, Vec *);

s32 func_00170380(Ch *c, Obj *o) {
    u16 *q;
    u32 j;
    Ch *sub;
    u32 i;
    H *h;
    u8 *d;
    u16 *p;
    u32 k;
    H *h2;
    u8 *d2;

    switch (c->x0) {
    case 0x4D415453:
        h = &c->h;
        sub = (Ch *)((u8 *)c + c->off);
        func_00102A60(&o->v, (Vec *)(DATA(h) + 0x10));
        D_0042D8B4[0] = *o->x10;
        D_0042D89C[0] = (E16 *)((s32)o + 0x40);
        D_0042D880[0] = 0;
        D_0042D884[0] = 0;
        D_0042D888[0] = 0;
        D_0042D88C[0] = 0;
        D_0042D890[0] = 0;
        D_0042D894[0] = 0;
        D_0042D898[0] = 0;
        D_0042D8A0[0] = (E8 *)(D_0042D89C[0] + o->x14);
        D_0042D8A4[0] = (s32 *)(D_0042D8A0[0] + o->x16);
        D_0042D8A8[0] = (E50 *)(D_0042D8A4[0] + o->x18);
        D_0042D8AC[0] = (s32 *)(D_0042D8A8[0] + o->x1C);
        d = (u8 *)(D_0042D8AC[0] + o->x1E);
        D_0042D8B8[0] = 0;
        D_0042D8B0[0] = (E8 *)d;
        for (i = 0; i < c->xE; i++) {
            func_00170380(sub, o);
            sub = (Ch *)((u8 *)sub + sub->x4);
        }
        break;
    case 0x4C54414D:
        h = &c->h;
        o->x24 = (s32)DATA(h) - D_0042D8B4[0];
        break;
    case 0x4C444F4D:
        sub = (Ch *)((u8 *)c + c->off);
        D_0042D8B8[0] = 1;
        for (i = 0; i < c->xE; i++) {
            func_00170380(sub, o);
            sub = (Ch *)((u8 *)sub + sub->x4);
        }
        D_0042D8B8[0] = 0;
        break;
    case 0x58524D57:
        h = &c->h;
        d = DATA(h);
        if (D_0042D8B8[0]) {
            (&D_0042D89C[0][D_0042D880[0]])->x8 = (s32)d - D_0042D8B4[0];
        }
        break;
    case 0x58524D4C:
        h = &c->h;
        d = DATA(h);
        if (D_0042D8B8[0]) {
            (&D_0042D89C[0][D_0042D880[0]])->xC = (s32)d - D_0042D8B4[0];
        }
        break;
    case 0x4D4F4547:
        h = &c->h;
        h2 = (H *)((u8 *)h + h->a);
        d = DATA(h);
        d2 = DATA(h2);
        (*(E16 **)D_0042D89C)[D_0042D880[0]].x0 = (s32)d - D_0042D8B4[0];
        (&D_0042D89C[0][D_0042D880[0]])->x4 = (s32)d2 - D_0042D8B4[0];
        D_0042D880[0]++;
        break;
    case 0x4D494E41:
        sub = (Ch *)((u8 *)c + c->off);
        for (i = 0; i < c->xE; i++) {
            func_00170380(sub, o);
            sub = (Ch *)((u8 *)sub + sub->x4);
        }
        break;
    case 0x51455341:
        h = &c->h;
        sub = (Ch *)((u8 *)c + c->off);
        (*(E8 **)D_0042D8A0)[D_0042D884[0]].x0 = (s32)DATA(h) - D_0042D8B4[0];
        (&D_0042D8A0[0][D_0042D884[0]])->x4 = D_0042D888[0];
        for (i = 0; i < c->xE; i++) {
            func_00170380(sub, o);
            sub = (Ch *)((u8 *)sub + sub->x4);
        }
        D_0042D884[0]++;
        break;
    case 0x5F4B5254:
        h = &c->h;
        (*(s32 **)D_0042D8A4)[D_0042D888[0]] = (s32)DATA(h) - D_0042D8B4[0];
        D_0042D888[0]++;
        break;
    case 0x4C425441:
        h = &c->h;
        o->x28 = (s32)DATA(h) - D_0042D8B4[0];
        break;
    case 0x494D5453:
    case 0x49435453:
    case 0x494F5453:
    case 0x49535453:
    case 0x4D495453:
    case 0x4D455453:
    case 0x4D584653:
        break;
    case 0x45545453:
        sub = (Ch *)((u8 *)c + c->off);
        for (i = 0; i < c->xE; i++) {
            if (sub->xC) {
                func_00170380(sub, o);
            }
            sub = (Ch *)((u8 *)sub + sub->x4);
        }
        break;
    case 0x6154584D:
        h = &c->h;
        (*(E8 **)D_0042D8B0)[D_0042D898[0]].x0 = (s32)DATA(h) - D_0042D8B4[0];
        (&D_0042D8B0[0][D_0042D898[0]])->x4 = (u32)c->h.c8 >> 16;
        (&D_0042D8B0[0][D_0042D898[0]])->x6 = c->h.c8 & 0xFFF;
        D_0042D898[0]++;
        break;
    case 0x43494454:
        o->x3C.f.b4 = 1;
        break;
    case 0x4D544948:
        sub = (Ch *)((u8 *)c + c->off);
        for (i = 0; i < c->xE; i++) {
            func_00170380(sub, o);
            sub = (Ch *)((u8 *)sub + sub->x4);
        }
        break;
    case 0x47544948:
        h = &c->h;
        d = DATA(h);
        h2 = (H *)((u8 *)h + h->a);
        d2 = DATA(h2);
        (*(E50 **)D_0042D8A8)[D_0042D88C[0]].x0 = (s32)d - D_0042D8B4[0];
        (&D_0042D8A8[0][D_0042D88C[0]])->x4 = (s32)d2 - D_0042D8B4[0];
        p = (u16 *)d;
        for (k = 0; k < 8; k++) {
            if (*p == 0) {
                (*(E50 **)D_0042D8A8)[D_0042D88C[0]].x10[k] = 0;
            } else {
                (*(E50 **)D_0042D8A8)[D_0042D88C[0]].x10[k] = (s32)(d + 0xA0) - D_0042D8B4[0] + p[8] * 32;
            }
            p++;
        }
        D_0042D88C[0]++;
        break;
    case 0x58424248:
        h = &c->h;
        d = DATA(h);
        (&D_0042D8A8[0][D_0042D890[0]])->x8 = (s32)d - D_0042D8B4[0];
        q = (u16 *)d;
        for (j = 0; j < 8; j++) {
            if (*q == 0) {
                (*(E50 **)D_0042D8A8)[D_0042D890[0]].x30[j] = 0;
            } else {
                (*(E50 **)D_0042D8A8)[D_0042D890[0]].x30[j] = (s32)(d + 0x120) - D_0042D8B4[0] + q[8] * 32;
            }
            q++;
        }
        D_0042D890[0]++;
        break;
    case 0x4547414B:
    case 0x4D47414B:
        sub = (Ch *)((u8 *)c + c->off);
        for (i = 0; i < c->xE; i++) {
            func_00170380(sub, o);
            sub = (Ch *)((u8 *)sub + sub->x4);
        }
        break;
    case 0x4747414B:
        h = &c->h;
        (*(s32 **)D_0042D8AC)[D_0042D894[0]] = (s32)DATA(h) - D_0042D8B4[0];
        D_0042D894[0]++;
        break;
    }
    return 1;
}

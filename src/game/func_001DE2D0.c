/* round 3 near-miss: 6 words: lw a2 (Col stack arg) vs lwc1 f12 order before func_001875C0, 3 sites */
#include "common.h"
typedef struct { f32 m[4]; f32 x; f32 y; } S;
typedef union { u32 w; s8 b[4]; } Col;
typedef struct { u8 pad0[0x10]; u8 x10[0x18]; s32 x28; u8 x2C[4]; f32 x30; f32 x34; f32 x38; f32 x3C; } O;
typedef struct { u8 p0[4]; u16 x4; u8 x6; u8 p7[3]; u16 xA; u8 pC[0x14]; u16 x20; u8 p22[0x1A]; u8 x3C; u8 p3D[0x53]; } E;
typedef struct { s32 x0; s32 x4; u8 p8[8]; u8 x10[0x10]; u8 x20[0x10]; } R;
typedef struct { u8 p0[0x300]; R r[2]; } Rs;
typedef struct { u8 p0[0x54]; Rs *x54; u8 p58[4]; Rs *x5C; } G;
extern S D_001F3A70 __attribute__((aligned(16)));
extern u32 D_00202378;
extern char D_004BAA70[];
extern char D_001FE748[];
extern char D_001FE750[];
extern char D_001FE758[];
extern char D_001FE768[];
extern char D_001FE790[];
extern char D_001FE798[];
extern char D_001FE7A0[];
extern u8 D_004BAB70[];
extern f32 D_004BAB84[];
extern f32 D_004BAB88[];
extern f32 D_004BAB9C[];
extern f32 D_004BABA0[];
extern u32 D_004BABAC[];
void func_00181680(s32, void *, void *, void *, S *, u32);
void func_001875C0(char *, s32, Col, f32, f32, f32);
G *func_00189020(s32);
void func_001848A0(s32);
u8 *func_001A97D0(s16);
u8 *func_001CC3F0(s16);
s32 func_00187130(s32, s32);
s32 func_001AFBD0(s32);
E *func_001AFC90(void);
void func_00183650(void *);
s32 sprintf(char *, const char *, ...);
char *strcpy(char *, const char *);
double fptodp(f32);
static inline f32 u2f(u32 x) { return x; }

void func_001DE2D0(O *o, s32 a1, u32 mode, s32 id) {
    S buf __attribute__((aligned(16)));
    Col c0;
    Col cA;
    Col c9;
    Col c1;
    Col cE;
    Col cD;
    u32 s;
    buf = D_001F3A70;
    c0.w = 0x80808080;
    if ((u32)(mode - 1000) <= 1 || mode == 1002) {
        switch (D_00202378) {
        case 2: case 3: case 4: case 5: case 6:
            return;
        }
    }
    if (mode < 600) {
        buf.x = o->x30;
        buf.y = o->x34;
        if (mode == 0) {
            o->x2C[0] = 0x40;
            o->x2C[1] = 0x40;
            o->x2C[2] = 0x40;
        }
        func_00181680(o->x28, o, o->x10, o->x2C, &buf, mode);
        return;
    }
    switch (mode) {
    case 0x259:
        break;
    case 0x25A:
        break;
    case 0x25B: {
        R *r;
        Rs *q = func_00189020(0)->x54;
        buf.x = o->x38;
        buf.y = o->x3C;
        r = &q->r[0];
        func_00181680(r->x4, r->x10, r->x20, o->x2C, &buf, 0);
        return;
    }
    case 0x25C: {
        R *r;
        Rs *q = func_00189020(0)->x5C;
        buf.x = o->x38;
        buf.y = o->x3C;
        r = &q->r[0];
        func_00181680(r->x4, r->x10, r->x20, o->x2C, &buf, 0);
        return;
    }
    case 0x25D:
        if (id > 0) {
            f32 f;
            s32 m;
            func_001848A0(id);
            m = 0;
            switch (D_00202378) {
            case 1:
            case 4:
                f = u2f(*func_001A97D0(id));
                m = 1;
                break;
            case 2:
            case 3:
            case 5:
            case 6:
                f = u2f(*func_001CC3F0(id));
                m = 0;
                break;
            case 0:
                break;
            }
            if (func_00187130(id, m) != 0) {
                cD.w = 0x80404080;
            } else {
                cD.w = 0x80808080;
            }
            sprintf(D_004BAA70, D_001FE748, (s32)f);
            if (func_001AFBD0(id) == 0) {
                strcpy(D_004BAA70, D_001FE750);
            } else if (func_001AFBD0(id) == 1) {
                E *e = &func_001AFC90()[id];
                switch (e->x20) {
                case 5:
                case 6:
                    strcpy(D_004BAA70, D_001FE750);
                    break;
                }
            }
            func_001875C0(D_004BAA70, 0, cD, ((volatile O *)o)->x38, o->x3C, 0.9f);
        }
        break;
    case 0x25E:
        if (id > 0) {
            s32 v = 0;
            E *e = &func_001AFC90()[id];
            if (e != NULL && id != -1) {
                if (e->xA == 1) {
                    e = &func_001AFC90()[id];
                    switch (e->x20) {
                    case 5:
                    case 6:
                        v = 0;
                        break;
                    default:
                        v = e->x3C;
                        break;
                    }
                } else if (e->xA == 2) {
                    v = e->x3C;
                }
                cE.w = 0x80808080;
                if (v == 0) {
                    strcpy(D_004BAA70, D_001FE758);
                } else {
                    sprintf(D_004BAA70, D_001FE790, v);
                }
                func_001875C0(D_004BAA70, 0, cE, ((volatile O *)o)->x38, o->x3C, 0.9f);
                return;
            }
        }
        break;
    case 0x25F: {
        R *r;
        Rs *q = func_00189020(0)->x54;
        buf.x = o->x38;
        buf.y = o->x3C;
        r = &q->r[1];
        func_00181680(r->x4, r->x10, r->x20, o->x2C, &buf, 0);
        return;
    }
    case 0x260: {
        R *r;
        Rs *q = func_00189020(0)->x5C;
        buf.x = o->x38;
        buf.y = o->x3C;
        r = &q->r[1];
        func_00181680(r->x4, r->x10, r->x20, o->x2C, &buf, 0);
        return;
    }
    case 0x261:
        if (id > 0) {
            E *e = &func_001AFC90()[id];
            c1.w = 0x80808080;
            sprintf(D_004BAA70, D_001FE768, fptodp(u2f(e->x4) / 10.0f));
            func_001875C0(D_004BAA70, 0, c1, ((volatile O *)o)->x38, o->x3C, 0.9f);
            return;
        }
        break;
    case 0x2711:
        D_004BAB9C[0] = o->x38;
        D_004BABA0[0] = o->x3C;
        D_004BAB84[0] = 1.0f;
        D_004BABAC[0] = 0x80FFFFFF;
        D_004BAB88[0] = 1.0f;
        func_00183650(D_004BAB70);
        return;
    case 0x3E8:
        buf.x = o->x30;
        buf.y = o->x34;
        func_00181680(o->x28, o, o->x10, o->x2C, &buf, mode);
        return;
    case 0x3E9: {
        c9.w = 0x80808080;
        func_001875C0(D_001FE798, 2, c9, ((volatile O *)o)->x38, o->x3C, 0.9f);
        return;
    }
    case 0x3EA:
        if (id > 0) {
            E *e = &func_001AFC90()[id];
            u8 *r = func_001A97D0(id);
            cA.w = 0x80808080;
            if (r[5] == 2) {
                sprintf(D_004BAA70, D_001FE7A0, 5);
            } else {
                sprintf(D_004BAA70, D_001FE7A0, e->x6);
            }
            func_001875C0(D_004BAA70, 2, cA, ((volatile O *)o)->x38, o->x3C, 0.9f);
            return;
        }
        sprintf(D_004BAA70, D_001FE750);
        func_001875C0(D_004BAA70, 2, c0, ((volatile O *)o)->x38, o->x3C, 0.9f);
        break;
    }
}


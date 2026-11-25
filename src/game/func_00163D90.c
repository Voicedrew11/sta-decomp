#include "common.h"
typedef struct B {
    u8 pad[0x10];
    Vec x10;
    u8 pad20[0xA0 - 0x20];
    u16 xA0;
    u8 padA2[0x114 - 0xA2];
    Flags8 f114;
    u8 pad115[0x120 - 0x115];
} B;
extern B *D_00201FC0;
B *func_00163C40(B *);
void func_00163C80(B *, Mtx *);
void func_001027B0(Vec *, Mtx *, Vec *);
void func_001029D0(Vec *, Vec *, Vec *);
void func_00102A60(Vec *, Vec *);
void func_00163D90(B *o, Vec *out);
static inline B *parent(B *o) {
    u16 i = o->xA0;
    if (i == 0xFFFF) return 0;
    return &D_00201FC0[i];
}
static inline void G(B *o, Vec *out) {
    B *p;
    Vec v;
    Mtx m4;
    p = func_00163C40(o);
    if (o->f114.f.b5 && p) {
        func_00163C80(p, &m4);
        func_00163D90(p, &v);
        func_001027B0(out, &m4, &o->x10);
        func_001029D0(out, out, &v);
    } else {
        func_00102A60(out, &o->x10);
    }
}

void func_00163D90(B *o, Vec *out) {
    B *p3;
    B *p1;
    B *p2;
    Vec w;
    Mtx m1;
    Vec u;
    Mtx m2;
    Vec t;
    Mtx m3;

    p1 = parent(o);
    if (o->f114.f.b5 && p1) {
        func_00163C80(p1, &m1);
        p2 = parent(p1);
        if (p1->f114.f.b5 && p2) {
            func_00163C80(p2, &m2);
            p3 = parent(p2);
            if (p2->f114.f.b5 && p3) {
                func_00163C80(p3, &m3);
                G(p3, &t);
                func_001027B0(&u, &m3, &p2->x10);
                func_001029D0(&u, &u, &t);
            } else {
                func_00102A60(&u, &p2->x10);
            }
            func_001027B0(&w, &m2, &p1->x10);
            func_001029D0(&w, &w, &u);
        } else {
            func_00102A60(&w, &p1->x10);
        }
        func_001027B0(out, &m1, &o->x10);
        func_001029D0(out, out, &w);
    } else {
        func_00102A60(out, &o->x10);
    }
}

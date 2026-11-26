#include "m2c.h"
typedef struct Node { s32 key; s32 x4; struct Node *val; } Node;
typedef struct Obj { s32 x0; s32 x4; s32 x8; s32 xC; s32 x10; f32 x14; Node *x18; } Obj;
typedef struct Desc Desc;
struct Desc {
    s32 *list;
    s32 n;
    f32 x8;
    Node *(*get)(s32);
    s32 (*f10)(s32);
    s32 x14;
    void (*f18)(s32, Obj *, Desc *);
};
void func_0017F990(Obj *);

void func_0017F650(Obj *o, Desc *d) {
    Node *old;
    s32 i;
    s32 key;
    s32 off;
    Node n;
    Node *np;
    Node **pv;

    if (o == NULL || d == NULL) {
        return;
    }
    old = o->x18;
    i = 0;
    if (i < d->n) {
        off = 0;
        pv = &n.val;
        np = &n;
        do {
            if (d->get != NULL) {
                if (d->list == NULL) {
                    goto next;
                }
                key = *(s32 *)((s8 *)d->list + off);
                *pv = d->get(key);
                n.key = key;
                if (*pv == NULL) {
                    goto next;
                }
                o->x18 = np;
            } else {
                *pv = old;
                o->x18 = np;
            }
            if (d->f10 != NULL) {
                if (d->list == NULL) {
                    goto next;
                }
                o->x8 = d->f10(*(s32 *)((s8 *)d->list + off));
            }
            if (d->f18 != NULL) {
                d->f18(i, o, d);
            } else {
                o->x14 = d->x8 - (f32)i;
            }
            func_0017F990(o);
        next:
            i++;
            off += 4;
        } while (i < d->n);
    }
}

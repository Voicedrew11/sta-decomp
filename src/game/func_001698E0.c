#include "m2c.h"
typedef struct {
    s32 x0;
    f32 f4;
    s32 x8;
    s8 l;   /* 0xC */
    s8 r;   /* 0xD */
    u8 pad[0x72];
} Node;
typedef struct {
    u8 pad[0x270];
    Node n[1];
} Tree;
void func_001698E0(Tree *t, Node *n);
static inline void g2(Tree *t, Node *n) {
    n->f4 = 0.0f;
    if (n->l) {
        func_001698E0(t, &t->n[n->l]);
    }
    if (n->r) {
        func_001698E0(t, &t->n[n->r]);
    }
}
static inline void g1(Tree *t, Node *n) {
    n->f4 = 0.0f;
    if (n->l) {
        g2(t, &t->n[n->l]);
    }
    if (n->r) {
        g2(t, &t->n[n->r]);
    }
}

void func_001698E0(Tree *t, Node *n) {
    n->f4 = 0.0f;
    if (n->l) {
        g1(t, &t->n[n->l]);
    }
    if (n->r) {
        g1(t, &t->n[n->r]);
    }
}

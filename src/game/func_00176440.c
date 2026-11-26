#include "m2c.h"
typedef struct E { s32 a; struct E *next; u128 *pkt; s32 pad; } E;
typedef struct { E *head; E *tail; } B;
typedef union { u128 q; u64 d[2]; } Q;
extern s32 D_0020200C;
extern u64 D_00202010;
extern u8 D_00438A30[];
extern B D_00438A70[];
extern E D_0043F080[];
u32 func_00155A90(void);
void func_001549D0(void);
u128 *func_00154A80(s32);

void func_00176440(u32 a) {
    u32 v = func_00155A90();
    u64 key = (u64)a + ((u64)v << 32);
    E *e;
    E **t;
    B *b;
    Q *p;
    Q q;

    if (D_00202010 != key) {
        D_00202010 = key;
        b = &D_00438A70[v];
        t = &b->tail;
        e = &D_0043F080[D_0020200C];
        D_00438A30[v >> 6] = 1;
        func_001549D0();
        p = (Q *)func_00154A80(1);
        q.q = 0;
        q.d[0] = 0x10000000;
        *p = q;
        e->a = a;
        e->pkt = (u128 *)p;
        if (*t) (*t)->next = e;
        *t = e;
        if (b->head == 0) b->head = e;
        D_0020200C++;
    }
}

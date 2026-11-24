#include "m2c.h"
typedef struct Node {
    s32 dst;
    s32 src;
    u32 size;
    struct Node *next;
    s32 pad10;
    u8 state:2;
    u8 rest:6;
} Node;
typedef struct {
    s32 pad[4];
    s32 nfree;      /* 0x10 */
    s32 nused;      /* 0x14 */
    u8 b0:1;
    u8 b1:1;
    u8 b2:1;
    u8 b3:1;
    u8 b4:1;
    u8 b5:3;
    Node *head;     /* 0x1C */
    Node *tail;     /* 0x20 */
    Node *dead;     /* 0x24 */
    Node *sent;     /* 0x28 */
} Pool;
void func_0010BCA0(s32, s32, u32);
void func_001789E0(s32, s32, u32);
void func_00123A88(s32, s32, u32);

s32 func_00128210(Pool *p) {
    u32 flag;
    Node *n;
    Node *next;
    Node *prev;
    s32 dst, src;
    u32 size;
    flag = p->b2;
    if (p->b3) return 0;
    if (p->nused == 0) {
        p->b1 = 0;
        return 1;
    }
    prev = NULL;
    for (n = p->head; n != NULL; n = next) {
        next = n->next;
        if (n->state == 2) {
            if (prev == NULL) p->head = next;
            else prev->next = next;
            if (n == p->tail) p->tail = prev;
            n->next = p->dead;
            p->dead = n;
        } else {
            dst = n->dst;
            src = n->src;
            if (src != dst) {
                size = n->size;
                if (size >= 0x1400 && dst - src > 0) {
                    func_0010BCA0(0, dst, size);
                    func_001789E0(n->src, n->dst, n->size >> 4);
                } else {
                    func_00123A88(src, dst, size);
                }
                n->dst = n->src;
            }
            prev = n;
        }
    }
    p->b1 = 0;
    p->b2 = 0;
    if (flag) {
        {
            Node *mn, *m;
            m = p->dead;
            if (m != p->sent) {
                do {
                    mn = m->next;
                p->sent->dst -= m->size;
                p->sent->size += m->size;
                m->dst = 0;
                m->src = 0;
                m->size = 0;
                m->state = 0;
                m->next = p->sent->next;
                p->sent->next = m;
                p->nfree++;
                p->nused--;
                    m = mn;
                } while (mn != p->sent);
            }
        }
        p->dead = p->sent;
    }
    p->b4 = 0;
    return flag;
}

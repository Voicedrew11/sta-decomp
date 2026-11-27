#include "m2c.h"
typedef struct Node { s32 a; s32 b; s32 size; struct Node *next; s32 pad; u8 st:2; u8 rest:6; } Node;
typedef struct { u8 pad[0x14]; s32 count; u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; u8 rest:3; u8 pad2[3]; Node *head; } Obj;

void Pool_PlanCompact_1_00128460(Obj *o, u32 limit) {
    s32 acc = 0;
    u32 sum = 0;
    Node *n;
    Node *next;

    if (o->b3 == 0) {
        o->b4 = 0;
        if (o->count == 0) {
            o->b1 = 1;
            return;
        }
        for (n = o->head; n != NULL; n = next) {
            next = n->next;
            if (n->st) {
                acc += n->size;
                n->st = 2;
                continue;
            }
            if (acc == 0) continue;
            n->b = n->a - acc;
            sum += n->size;
            if (!(sum < limit)) break;
        }
        if (n == NULL) {
            o->b2 = 1;
        }
        o->b1 = 1;
        o->b4 = 1;
    }
}

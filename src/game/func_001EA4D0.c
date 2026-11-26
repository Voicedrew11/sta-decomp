#include "common.h"
typedef struct { s64 a; s64 b; s32 pos; s32 len; } E;
typedef struct { char p0[8]; s32 x8; char pc[0x44]; E *ents; s32 n; s32 cnt; s32 head; } O;
typedef struct { char p0[0x10]; s32 pos; s32 len; } B;
s32 func_001EA690(O *o, s32 pos);

static inline void rel(E *e) {
    if (e->a >= 0) {
        e->a = -1;
        e->b = -1;
        e->pos = 0;
        e->len = 0;
    }
}

static inline void dec(O *o) {
    s32 c = o->cnt - 1;
    o->cnt = c < 0 ? 0 : c;
}

s32 func_001EA4D0(O *o, B *b) {
    E *e;
    s32 i;
    s32 sz;
    s32 go = 1;
    s32 d;
    i = (o->n + (o->head - o->cnt)) % o->n;
    sz = o->x8 << 11;
    if (o->cnt > 0) {
        do {
            e = &o->ents[i];
            if (e->len == 0 || b->len == 0)
                break;
            if (func_001EA690(o, b->pos)) {
                rel(e);
                dec(o);
            } else if ((e->pos + sz - b->pos) % sz < b->len) {
                d = b->pos + b->len - e->pos;
                e->pos = e->pos + d;
                e->len = e->len - d;
                if (e->len == 0) {
                    rel(e);
                    dec(o);
                }
            } else {
                go = 0;
            }
            i = (i + 1) % o->n;
        } while (go);
    }
    return 0;
}

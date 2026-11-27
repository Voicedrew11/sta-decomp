#include "m2c.h"
extern s8 * D_001F1C50[];
extern s8 * D_001F2300[];
extern s8 * D_0033F500[];
typedef struct { u8 type; u8 pad[3]; s32 val; } Ent;
typedef struct { u8 pad[0xC]; u16 c; u16 e; } Hdr;
static inline s8 *get(u8 i, s32 v) {
    s8 *r = NULL;
    if (i < 0x40) {
        if (i >= 0x20) r = (s8 *)(D_001F2300[i] + v); else if (i >= 0x10) r = (s8 *)(D_001F1C50[i] + v); else r = (s8 *)(D_0033F500[i] + v);
    }
    return r;
}

s8 *Script_ResolveOperand_1_00165150(s32 arg0, Hdr *arg1, Ent *arg2) {
    s32 t = arg2->type;
    s8 *ret = NULL;
    switch ((s64)t) {
    case 0x11:
        ret = get(t, arg2->val);
        break;
    case 0x12: {
        s32 v = arg2->val;
        u32 sz = ((s32)v + 7) & ~3;
        if ((u32)arg1->e < sz) arg1->e = sz;
        ret = (s8 *)(v + (arg1->c + (s32)arg1) + 0x158);
        break;
    }
    case 0x13:
        ret = (s8 *)(arg2->val + arg0 + 0x14);
        break;
    }
    return ret;
}

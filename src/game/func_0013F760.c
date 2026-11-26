#include "m2c.h"
typedef struct { u8 pad[0x1A]; u16 val; u8 pad2[0x54-0x1C]; } Ent;
typedef struct { u8 pad[0x13C]; Ent *ents; } Tbl;
typedef struct { Tbl *tbl; } Hdr;
void func_001AA2A0(s32, s16);
void func_001AA1E0(s32, s16);
void func_001AA130(s32);

void func_0013F760(s8 *arg0, s32 a1) {
    u8 flag;
    u8 lo;
    s32 hi;
    u16 idx;
    Hdr *pp;
    Ent *q;
    flag = ((u64)((s64)*(u8 *)(arg0 + 0x5A1) << 0x3C) >> 0x3F);
    if (flag) lo = *(u16 *)(arg0 + 0x710) % 100;
    else {
        pp = *(Hdr **)(arg0 + 0x4A8); idx = *(u16 *)(arg0 + 0x4AC);
        q = pp ? &pp->tbl->ents[idx] : NULL;
        if (q) lo = q->val % 100; else lo = *(u16 *)(arg0 + 0x710) % 100;
    }
    if (flag) hi = *(u16 *)(arg0 + 0x712);
    else { pp = *(Hdr **)(arg0 + 0x4A8); if (pp) hi = *(s32 *)pp->tbl; else hi = 0; }
    func_001AA2A0(hi, lo);
    func_001AA1E0(hi, lo);
    if (a1) func_001AA130(hi);
}

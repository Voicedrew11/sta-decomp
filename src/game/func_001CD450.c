#include "m2c.h"
s8 *func_001C9BA0();
u8 *func_001AFC90(void);
typedef struct { u8 pad0[0x22]; u8 k[2]; u8 v[2]; u8 pad2[0x90-0x26]; } E;

s32 func_001CD450(s32 a0, u8 *out, s32 a2, s32 a3) {
    u8 *p = (u8 *)func_001C9BA0();
    E *base = (E *)func_001AFC90();
    s16 idx;
    s16 *slots;
    s32 found;
    u8 val;
    s32 i, j;
    found = 0;
    val = a3 ? 0 : 0xFF;
    slots = (s16 *)(p + 0x80);
    if (a2) {
        idx = slots[p[0x94] & 1];
        if (idx > 0) {
            for (j = 0; j < 2; j++) {
                if ((u8)a0 == base[idx].k[j]) {
                    if (a3) {
                        val = (base[idx].v[j] < val) ? val : base[idx].v[j];
                    } else {
                        val = (val < base[idx].v[j]) ? val : base[idx].v[j];
                    }
                    found = 1;
                }
            }
        }
        if (out) *out = val;
        return found;
    }
    for (i = 0; i < 2; i++) {
        idx = slots[i];
        if (idx > 0) {
            for (j = 0; j < 2; j++) {
                if ((u8)a0 == base[idx].k[j]) {
                    if (a3) {
                        val = (base[idx].v[j] < val) ? val : base[idx].v[j];
                    } else {
                        val = (val < base[idx].v[j]) ? val : base[idx].v[j];
                    }
                    found = 1;
                }
            }
        }
    }
    for (i = 2; i < 9; i++) {
        idx = slots[i];
        if (idx > 0) {
            for (j = 0; j < 2; j++) {
                if ((u8)a0 == base[idx].k[j]) {
                    if (a3) {
                        val = (base[idx].v[j] < val) ? val : base[idx].v[j];
                    } else {
                        val = (val < base[idx].v[j]) ? val : base[idx].v[j];
                    }
                    found = 1;
                }
            }
        }
    }
    if (out) *out = val;
    return found;
}

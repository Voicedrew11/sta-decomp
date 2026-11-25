#include "m2c.h"
typedef struct { u8 pad[0x20]; u16 x20; u8 pad22[0x6E]; } E;
E *func_001AFC90(void);
static inline s32 two(E *e) {
    switch (e->x20) {
    case 2:
    case 4:
    case 6:
    case 9:
    case 0xB:
    case 0xC:
    case 0xD:
    case 0xF:
    case 0x10:
    case 0x11:
    case 0x12:
    case 0x13:
        return 1;
    }
    return 0;
}

void func_001CCF50(s16 *slots, s32 idx, s16 id) {
    E *base = func_001AFC90();
    s32 cur;

    if (idx < 0 || idx >= 10) {
        return;
    }
    if (slots == NULL) {
        return;
    }
    if (idx >= 2) {
        if (id == slots[idx]) {
            slots[idx] = -1;
        } else {
            slots[idx] = id;
        }
        return;
    }
    cur = slots[idx];
    if (id == -1 || id == cur) {
        if (cur <= 0) {
            return;
        }
        if (two(&base[cur])) {
            slots[idx] = -1;
            slots[!idx] = -1;
        } else {
            slots[idx] = -1;
        }
        return;
    }
    if (two(&base[id])) {
        slots[idx] = id;
        slots[!idx] = id;
        return;
    }
    if (cur > 0 && two(&base[cur])) {
        slots[idx] = -1;
        slots[!idx] = -1;
    }
    slots[idx] = id;
    if (slots[!idx] == id) {
        slots[!idx] = -1;
    }
}

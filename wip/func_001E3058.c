/* round 2 near-miss: ee-gcc, 5 words: lo+hi in a2 instead of v0, one slt in v1 */
#include "common.h"
typedef struct { u16 lo, hi, base; } E;
typedef struct { u8 pad[0x10]; u16 n; s32 x14; s32 x18; } H;
typedef struct { u8 pad[0x28]; H *h; } G;
extern G *D_00201E5C;
void func_00121C28(s32) __attribute__((noreturn));

u8 *func_001E3058(u16 key) {
    
    s32 lo, hi, mid;
    E *e;
    lo = 0;
    if (D_00201E5C->h == 0) func_00121C28(1);
    lo = 0;
    hi = D_00201E5C->h->n - 1;
    mid = (lo + hi) / 2;
    e = (E *)((u8 *)D_00201E5C->h + D_00201E5C->h->x14) + mid;
    if (key < e->lo) {
        if (lo >= hi) return 0;
        hi = mid - 1;
        goto loop;
    }
chk:
    if (key > e->hi) {
        if (lo >= hi) return 0;
        lo = mid + 1;
        goto loop;
    }
    return (u8 *)D_00201E5C->h + D_00201E5C->h->x18 + (e->base + key - e->lo) * 0x18;
loop:
    mid = lo + hi;
    mid /= 2;
    e = (E *)((u8 *)D_00201E5C->h + D_00201E5C->h->x14) + mid;
    if (key < e->lo) {
        if (lo < hi) { hi = mid - 1; goto loop; }
        return 0;
    }
    goto chk;
}

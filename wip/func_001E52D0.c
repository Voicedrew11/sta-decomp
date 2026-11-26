/* round 3 near-miss: ee-gcc, 6 words: D2_QWC/D2_MADR constants in v0/v1 swapped */
#include "common.h"
void FlushCache(s32);
void func_00101120(s32, s32);
u32 *func_001E51A8(void *, u16, s32);
u32 *func_001E51D0(void *, s32, s32, s32, s32, s32, u64);
u32 *func_001E52A8(void *, s64, s64);
u32 *func_001E52B8(void *, u32, u32, u32, u32);
void func_001E54E8(void *, u64 *, void *);
typedef struct { s32 x0, y0, x1, y1; } Rect;
typedef struct { u32 a, b, c, d; } Q4;
typedef struct { u8 pad[0x18]; void *x18; u8 pad1C[0x24]; u32 x40[4]; } Ctx;

void func_001E52D0(Rect *r, u32 *uv, u8 *c) {
    u64 t;
    u32 *p;

    if (r->x0 < 0x280 && r->y0 < 0xE0 && r->x1 >= 0 && r->y1 >= 0 && r->x0 != r->x1 && r->y0 != r->y1) {
        func_001E54E8(*(void **)(c + 0x18), &t, 0);
        p = func_001E51A8((void *)0x70000000, 0xA, 7);
        p = func_001E51D0(p, 1, 1, 0x5E, 0, 9, 0x52521EEEEULL);
        p = func_001E52A8(p, 8, 5);
        p = func_001E52A8(p, 0x47, 0x71001);
        p = func_001E52A8(p, 0x42, 0x44);
        p = func_001E52A8(p, 6, t);
        p = func_001E52B8(p, (u32)(c + 0x40), (u32)(c + 0x44), (u32)(c + 0x48), (u32)(c + 0x4C));
        p = func_001E52B8(p, uv[0], uv[1], 0x3F800000, 0);
        p = func_001E52B8(p, (r->x0 + 0x6C0) << 4, (r->y0 / 2 + 0x790) << 4, 0x1000000, 0);
        p = func_001E52B8(p, uv[2], uv[3], 0x3F800000, 0);
        p = func_001E52B8(p, (r->x1 + 0x6C0) << 4, (r->y1 / 2 + 0x790) << 4, 0x1000000, 0);
        func_00101120(0, 0);
        *(volatile s32 *)0x1000A020 = 0;
        *(volatile s32 *)0x1000A010 = 0;
        *(volatile s32 *)0x1000A030 = 0xF0000000;
        FlushCache(0);
        *(volatile s32 *)0x1000A000 = 0x145;
        func_00101120(0, 0);
    }
}


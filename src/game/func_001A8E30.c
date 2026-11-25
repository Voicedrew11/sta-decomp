#include "m2c.h"
#include "common.h"
typedef struct { u8 pad[0x20]; u8 x20[0xE]; u8 x2E; u8 p2F; s16 x30, x32, x34, x36, x38; } D;
extern D *D_00201DC0;
void func_001C9630(Vec *, Vec *);
void func_001C9BB0(u8 *);
void func_001DFAA0(u8 *);
void func_001DF9A0(void);

void func_001A8E30(void) {
    Vec a;
    Vec b;

    a.x = D_00201DC0->x30;
    a.y = D_00201DC0->x32;
    a.z = D_00201DC0->x34;
    a.w = 0.0f;
    b.x = 0.00024414062f * D_00201DC0->x36;
    b.y = 0.00024414062f * D_00201DC0->x38;
    b.w = 0.0f;
    b.z = 0.0f;
    if (D_00201DC0->x2E != 1) {
        func_001C9630(&a, &b);
    }
    func_001C9BB0(D_00201DC0->x20);
    func_001DFAA0((u8 *)D_00201DC0 + 0xB8);
    func_001DF9A0();
}

#include "actor.h"
typedef struct {
    u8 pad[0x39C];
    u8 u39C;
    u8 pad2[4];
    Flags8 f3A1;
    u8 pad3[0x3D4 - 0x3A2];
    u8 u3D4;
    u8 u3D5;
    Flags8 f3D6;
    union { u8 b; struct { u8 b0:1; u8 b1:2; u8 r:5; } f; } f3D7;
} Obj;
void func_001C6590(s32);
s32 func_0012C020(void);
void func_001CC5E0(void);
static inline Obj *get(void) {
    if (D_002022E4 == NULL) {
        return NULL;
    }
    if (D_002022E4->unk518 == NULL) {
        return NULL;
    }
    return (Obj *)(D_002022E4->unk518 + 0x180);
}

void func_001C5FB0(void) {
    Obj *p = get();
    if (p == NULL) return;
    switch (p->u3D5) {
    case 0: break;
    case 1:
        if (p->f3A1.f.b6) {
            { if (p->u39C == 0x12) func_001C6590(8);
            else func_001C6590(7); } if (p && p) {} /* scheduling barrier: keeps the b-to-b hop */
        } else if (p->f3D6.f.b3) {
            func_001C6590(2);
        } else if (p->f3D7.f.b1) {
            func_001C6590(3);
        }
        break;
    case 2: break;
    case 3:
        if (func_0012C020()) {
            func_001C6590(6);
        } else if (p->f3A1.f.b6) {
            { if (p->u39C == 0x12) func_001C6590(8);
            else func_001C6590(6); } if (p && p) {} /* scheduling barrier: keeps the b-to-b hop */
        } else if (p->f3D6.f.b3) {
            func_001C6590(6);
        }
        break;
    case 4:
        p->f3D6.f.b0 = 1;
        if (p->f3D7.f.b1) {
            func_001CC5E0();
            if (p->u39C == 0x12) {
                func_001C6590(0);
                p->u3D4 = 0;
            } else {
                func_001C6590(3);
            }
        }
        break;
    case 5:
        p->f3D6.f.b1 = 1;
        if (p->f3D7.f.b1) func_001C6590(3);
        break;
    case 6:
        if (p->f3D7.f.b1) func_001C6590(0);
        break;
    case 7:
        if (p->f3D7.f.b1) func_001C6590(0);
        break;
    }
}

#include "m2c.h"
typedef struct { u8 a:4; u8 b:1; u8 c:3; } BF;
void func_001AC820(void *, s32, s32);
void func_001549D0(void);
extern BF D_00222A50[];
extern u8 D_004AC630[];
extern u8 D_004AC970[];
extern u8 D_004AE370[];

void func_001ACEB0(s32 arg0) {
    s32 i;
    u8 *p;
    u8 *q;
    s32 j;
    u8 *r;
    s32 k;
    for (i = 0, p = D_004AE370; i < 0x40; i++, p += 0xD0) {
        func_001AC820(p, arg0, 1);
        func_001AC820(p + 0x3400, arg0, 1);
    }
    for (j = 0, q = D_004AC970; j < 0x10; j++, q += 0xD0) {
        func_001AC820(q, arg0, 0);
        func_001AC820(q + 0xD00, arg0, 0);
    }
    D_00222A50[0].b = 1;
    for (k = 0, r = D_004AC630; k < 4; k++, r += 0xD0) {
        func_001AC820(r, arg0, 0);
    }
    D_00222A50[0].b = 0;
    func_001549D0();
}

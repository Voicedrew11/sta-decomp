#include "common.h"
void func_0010E268(s32);
void func_0015B040(s32, s32);
s32 func_00113CC0(void *);
s32 func_00113C88(void);
void func_00112870(void);
void func_00112F50(void);
void func_0010FA98(void);
s32 *func_00122EB8(s32);
void func_00122F10(s32 *);
extern u8 D_001FB770[];
extern u8 D_4BE180[];
void func_00100000(void);
static inline s32 sub(s32 a, s32 b) { return a - b; }
static inline s32 top(void) { return (s32)func_00100000 + 0x1000; }
static inline s32 add(s32 a, s32 b) { return a + b; }
extern s32 D_00201F90;

void func_0015CB50(void) {
    s32 n;
    s32 *p;
    func_0010E268(0);
    func_0015B040(0x200, 1);
    while (!(func_00113CC0(D_001FB770) != 0) != 0) {}
    while (!(func_00113C88() != 0) != 0) {}
    func_0010E268(0);
    func_00112870();
    func_00112F50();
    func_0010FA98();
    func_0015B040(0x200, 1);
    n = sub(0x2000000, (s32)D_4BE180 + top() + 0x1000) - 0x10;
    p = func_00122EB8(n);
    if (p != 0) {
        func_00122F10(p);
    }
    D_00201F90 = n;
}

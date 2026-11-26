#include "common.h"
extern struct { char pad[0x88]; s32 state; s32 x8c; } D_004B63B8;
s32 func_001D3E30(void);
s32 func_001D3FE8(void);
s32 func_001D4170(void);
s32 func_001D4A78(void);
s32 func_001D5280(void);
s32 func_001D58C0(void);
s32 func_001D6428(void);
s32 func_001D6550(void);
s32 func_001D6688(void);
s32 func_001D5F88(void);
s32 func_001D67A8(void);

s32 func_001D6D00(void) {
    s32 r = -1;
    s32 s;
    switch (D_004B63B8.state) {
    case 3: r = func_001D3E30(); break;
    case 4: r = func_001D3FE8(); break;
    case 5: r = func_001D4170(); break;
    case 6: r = func_001D4A78(); break;
    case 7: r = func_001D5280(); break;
    case 8: r = func_001D58C0(); break;
    case 9: r = func_001D6428(); break;
    case 10: r = func_001D6550(); break;
    case 11: r = func_001D6688(); break;
    case 12: r = func_001D5F88(); break;
    case 13: r = func_001D67A8(); break;
    case 0: return 0;
    case 1:
    case 2: r = -1; break;
    }    if (r < 0) {
        r = -D_004B63B8.state;
        D_004B63B8.x8c = 0;
        D_004B63B8.state = 0;
        s = -100;
        if (r != 0) s = r;
        return s;
    }    if (r > 0) {
        D_004B63B8.state = 0;
        D_004B63B8.x8c = 0;
        return 0;
    }
    return D_004B63B8.state;
}

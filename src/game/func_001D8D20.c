#include "common.h"
s32 strlen(const char *);
s32 func_001D8680(s32, s32, s32, ...);
s32 func_001D8350(s32, s32, s32, s32, s32, const char *);
s32 func_001D84F0(s32, s32, s32, s32);
s32 func_001D8D20(s32 a0, const char *s, s32 a2) {
    s32 n = strlen(s);
    if (!func_001D8680(5, 1, 0x3010000, a0, a2)) {
        func_001D8680(5, 1, 0x3040000, a0);
        return 0;
    }
    if (!func_001D8350(5, 1, n + 1, 0, a0 | 0x30C0000, s)) {
        func_001D84F0(5, 1, 0x3040000, a0);
        return 0;
    }
    return 1;
}

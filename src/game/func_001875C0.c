#include "common.h"
typedef struct { u32 w; } C;
typedef struct { f32 x; f32 y; u8 b:3; u8 r:5; u8 p9[0xB]; f32 x64; u8 p68[8]; f32 z; f32 x74; } S;
u32 strlen(char *);
void func_00187A90(S *, char *, u64);
void func_00188010(S *, C);
void func_001875C0(char *str, s32 k, C c, f32 x, f32 y, f32 z) {
    S s;
    if (str != NULL) {
        func_00187A90(&s, str, strlen(str));
        s.x74 = 1.0f;
        s.b = k;
        s.x = x;
        s.y = y;
        s.x64 = 4096.0f;
        s.z = z;
        func_00188010(&s, c);
    }
}



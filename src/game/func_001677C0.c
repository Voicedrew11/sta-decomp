#include "m2c.h"
typedef struct { u8 p:1; u8 v:1; } B;
typedef struct { f32 pad[8]; f32 x; f32 p1; f32 z; f32 p2; f32 v[4]; } S;
void func_00102A60(s8 *, f32 *);
void func_00102A70(s8 *, S *);
void func_00145FB0(S *);
void func_00146140(f32, f32, s8 *);

void func_001677C0(s8 *arg0) {
    S s;

    if (arg0 != NULL) {
        func_00145FB0(&s);
        if (arg0 != NULL) {
            if (((B *)(*(s8 **)(arg0 + 0x210) + 0x94))->v) {
                func_00146140(s.x, s.z, arg0);
                func_00102A60(arg0 + 0x30, s.v);
                return;
            }
            func_00102A70(arg0, &s);
        }
    }
}

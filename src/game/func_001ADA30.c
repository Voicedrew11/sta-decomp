#include "m2c.h"
typedef struct { s8 pad[0x44]; f32 f44; s8 pad2[0x84-0x48]; s8 *p84; s8 pad3[0x9C-0x88]; s16 h9C; s8 pad4[0xA8-0x9E]; u8 bA8; s8 pad5[0xD0-0xA9]; } Obj;
extern Obj D_004AC630[4];
extern Obj D_004AC970[2][16];
extern Obj D_004AE370[2][64];
void func_001AD4E0(Obj *, f32);
void func_001AF4A0(Obj *);
void func_001AE510(void);

void func_001ADA30(f32 arg0) {
    s32 i;

    for (i = 0; i < 0x40; i++) {
        func_001AD4E0(&D_004AE370[0][i], arg0);
        func_001AD4E0(&D_004AE370[1][i], arg0);
    }
    for (i = 0; i < 0x10; i++) {
        func_001AD4E0(&D_004AC970[0][i], arg0);
        func_001AD4E0(&D_004AC970[1][i], arg0);
    }
    for (i = 0; i < 4; i++) {
        func_001AD4E0(&D_004AC630[i], arg0);
    }
    for (i = 0; i < 0x10; i++) {
        if (D_004AC970[0][i].h9C != -1 && !(D_004AC970[0][i].f44 < 29000.0f)) {
            func_001AF4A0(&D_004AC970[0][i]);
            func_001AE510();
        }
        if (D_004AC970[1][i].h9C != -1 && !(D_004AC970[1][i].f44 < 29000.0f)) {
            func_001AF4A0(&D_004AC970[1][i]);
            func_001AE510();
        }
    }
    func_001AE510();
}

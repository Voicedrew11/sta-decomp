#include "m2c.h"
typedef struct {
    u8 pad[0x188];
    u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:1; u8 b6:1; u8 b7:1;
    u8 rest[0xED0 - 0x189];
} E;
typedef struct { u16 prev; u16 next; u16 x4; } L;
void sceVu0CopyVector(void *, void *);
void memset(void *, s32, s32);
void Sfx_Free_1_001670E0(E *);
void Sfx_UpdateAll_1_00169400(f32);
void GlowFx_StopAll_0_001E0E80(void);
extern s16 D_00201CA0;
extern u32 D_00201FAC;
extern void *D_00201FC0;
extern L *D_00201FD4;
extern s16 D_00201FD8;
extern s8 D_003139A0[];
extern s8 D_003406D0[];
extern E D_003407E0[];

void Sfx_ClearAll_1_0016AB50(void) {
    s32 i;
    E *e;
    u32 j;

    for (i = 0, e = D_003407E0; i < 0x100; i++, e++) {
        if (e >= D_003407E0 && !(&D_003407E0[0xFF] < e)) {
            Sfx_Free_1_001670E0(e);
            e->b0 = 1;
            e->b4 = 1;
            e->b3 = 1;
        }
    }
    Sfx_UpdateAll_1_00169400(1.0f);
    Sfx_UpdateAll_1_00169400(1.0f);
    GlowFx_StopAll_0_001E0E80();
    sceVu0CopyVector(D_003406D0, D_003139A0);
    memset(D_00201FC0, 0, D_00201FAC * 0x120);
    D_00201FD8 = D_00201FAC;
    for (j = 0; j < D_00201FAC; j++) {
        D_00201FD4[j].prev = j - 1;
        D_00201FD4[j].next = j + 1;
        D_00201FD4[j].x4 = 0xFFFF;
    }
    D_00201FD4[0].prev = 0xFFFF;
    D_00201FD4[D_00201FAC - 1].next = 0xFFFF;
    D_00201CA0 = 0;
    memset(D_003407E0, 0, sizeof(E) * 0x100);
}

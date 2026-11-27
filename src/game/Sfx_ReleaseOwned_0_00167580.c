#include "common.h"
s32 ActorList_FromHandle_1_001A5970(void);
typedef struct { u8 pad[0x170]; s32 x170; u8 pad2[0xED0 - 0x174]; } E;
extern E D_003407E0[];
void Sfx_ReleaseOwned_0_00167580(void) {
    s32 id = ActorList_FromHandle_1_001A5970();
    s32 i = 0;
    E *e = D_003407E0;
    do {
        if (e->x170 == id) {
            e->x170 = 0;
        }
        i++;
        e++;
    } while (i < 0x100);
}

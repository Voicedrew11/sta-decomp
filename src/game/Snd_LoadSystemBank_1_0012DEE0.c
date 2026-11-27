#include "common.h"
void Pool_Free_2_00128580(s32, u8 **);
void SndCh_StopGroup_1_0012E730(s32);
void Arc_LoadFile_2_00159DD0(s32, s32, u8 ***, s32 *);
s32 SndBank_LoadStam_1_0012E6B0(u8 *);
extern u8 **D_00201EBC;
extern s8 D_00201ED4;
s32 Snd_LoadSystemBank_1_0012DEE0(s32 a) {
    s32 sz;
    u8 *p;
    D_00201ED4 = 1;
    SndCh_StopGroup_1_0012E730(0);
    Arc_LoadFile_2_00159DD0(0xE728760E, a, &D_00201EBC, &sz);
    p = *D_00201EBC;
    switch (*(s32 *)p) {
    case 0x4D415453:
        if (SndBank_LoadStam_1_0012E6B0(p) == -1) {
            Pool_Free_2_00128580(a, D_00201EBC);
            return -1;
        }
    }
    Pool_Free_2_00128580(a, D_00201EBC);
    return 0;
}

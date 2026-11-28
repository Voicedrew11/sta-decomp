#include "common.h"
typedef struct { s8 b0; char p1[0xD]; s8 bE; s8 bF; char rest[0x70]; } E_SndCh_StopAllUnlooped_1_0012C210;
typedef struct { s8 b0; char p1[2]; s8 b3; char p4[0xA]; s8 bE; s8 bF; char p10[0x5E]; s8 b6E; char rest[0x11]; } E_SndCh_ResumePaused_1_0012C260;
typedef struct { s8 b0; char p1[0xD]; s8 bE; s8 bF; char p10[0x5D]; s8 b6D; char rest[0x12]; } E_SndCh_PauseAll_1_0012C2C0;
extern E_SndCh_StopAllUnlooped_1_0012C210 D_0022CBC0[];
void SndCh_StopAllUnlooped_1_0012C210(void);
void SndCh_ResumePaused_1_0012C260(void);
void SndCh_PauseAll_1_0012C2C0(void);

/* SndCh_StopAllUnlooped_1_0012C210 */
void SndCh_StopAllUnlooped_1_0012C210(void)
{
    s32 i;
    for (i = 0; i < 63; i++) {
        if (D_0022CBC0[i].b0 && !D_0022CBC0[i].bF)
            D_0022CBC0[i].bE = 1;
    }
}

/* SndCh_ResumePaused_1_0012C260 */
#define D_0022CBC0 D_0022CBC0__as_SndCh_ResumePaused_1_0012C260
extern E_SndCh_ResumePaused_1_0012C260 D_0022CBC0__as_SndCh_ResumePaused_1_0012C260[63];

void SndCh_ResumePaused_1_0012C260(void)
{
    s32 i;
    for (i = 0; i < 63; i++) {
        if (D_0022CBC0[i].b0 && D_0022CBC0[i].bF && D_0022CBC0[i].bE == 2) {
            D_0022CBC0[i].b3 = 1;
            D_0022CBC0[i].bE = 3;
            D_0022CBC0[i].b6E = 0;
        }
    }
}
#undef D_0022CBC0

/* SndCh_PauseAll_1_0012C2C0 */
#define D_0022CBC0 D_0022CBC0__as_SndCh_PauseAll_1_0012C2C0
extern E_SndCh_PauseAll_1_0012C2C0 D_0022CBC0__as_SndCh_PauseAll_1_0012C2C0[63];

void SndCh_PauseAll_1_0012C2C0(void)
{
    s32 i;
    for (i = 0; i < 63; i++) {
        if (D_0022CBC0[i].b0 && D_0022CBC0[i].bF && D_0022CBC0[i].bE != 1) {
            D_0022CBC0[i].b6D = D_0022CBC0[i].bE;
            D_0022CBC0[i].bE = 2;
        }
    }
}
#undef D_0022CBC0

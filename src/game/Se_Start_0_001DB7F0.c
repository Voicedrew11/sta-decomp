/* Turn a sound channel's output on once; the same shape as Strm_DrvInit_0_001D8E30
 * and KFIV's SoundDriver_EnableOutput (kfiv-decomp src/game/sound/sound.c). */

typedef unsigned short u16;

extern u16 D_004BAA36[];
void SndDrv_Call_2_001D85D0(int, int, int);

void Se_Start_0_001DB7F0(void)
{
    if (D_004BAA36[0] != 1) {
        SndDrv_Call_2_001D85D0(4, 1, 0x500);
        D_004BAA36[0] = 1;
    }
}

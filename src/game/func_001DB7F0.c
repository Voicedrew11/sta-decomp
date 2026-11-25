/* Turn a sound channel's output on once; the same shape as func_001D8E30
 * and KFIV's SoundDriver_EnableOutput (kfiv-decomp src/game/sound/sound.c). */

typedef unsigned short u16;

extern u16 D_004BAA36[];
void func_001D85D0(int, int, int);

void func_001DB7F0(void)
{
    if (D_004BAA36[0] != 1) {
        func_001D85D0(4, 1, 0x500);
        D_004BAA36[0] = 1;
    }
}

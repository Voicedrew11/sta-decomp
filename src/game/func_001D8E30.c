/* Turn the sound driver's output on once.
 * cf. KFIV's SoundDriver_EnableOutput (kfiv-decomp src/game/sound/sound.c),
 * which sends the same kind of remote command and sets the same flag. */

typedef unsigned short u16;

extern u16 D_0020230C;
void func_001D85D0(int, int, int);

void func_001D8E30(void)
{
    if (D_0020230C != 1) {
        func_001D85D0(5, 1, 0x30000);
        D_0020230C = 1;
    }
}

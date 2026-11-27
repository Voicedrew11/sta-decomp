/* Start a fade: mode 3 when `out`, else 6, and reset the fade flags.
 * cf. KFIV's Game_StartFadeOut (kfiv-decomp src/game/core/game.c). */

extern int D_00201C28;
extern int D_00201EA4, D_00201EA8, D_00201E98, D_00201E9C;

void Game_RequestExit_0_0012C070(int out)
{
    if (out)
        D_00201C28 = 3;
    else
        D_00201C28 = 6;
    D_00201EA4 = 0;
    D_00201EA8 = 0;
    D_00201E98 = 1;
    D_00201E9C = 0;
}

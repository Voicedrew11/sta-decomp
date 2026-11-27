#include "common.h"

void Hud_HandleInput_0_0019B590(void);
void Hud_UpdateWeaponSlots_0_0019C560(void);
void Hud_UpdateShortcuts_0_0019BFF0(void);

void Hud_Update_1_0019B560(void)
{
    Hud_HandleInput_0_0019B590();
    Hud_UpdateWeaponSlots_0_0019C560();
    Hud_UpdateShortcuts_0_0019BFF0();
}

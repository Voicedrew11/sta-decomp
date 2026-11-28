#include "common.h"
#include "game/ui.h"
extern f32 D_00201CD0;

/* Ui_Nop_2_00180F40 */
void Ui_Nop_2_00180F40(void) {

}

/* Ui_SetScrollSpeed_0_00180F50 */
void Ui_SetScrollSpeed_0_00180F50(f32 fparg0) {
    D_00201CD0 = 4.266667f * (fparg0 / 30.0f);
}

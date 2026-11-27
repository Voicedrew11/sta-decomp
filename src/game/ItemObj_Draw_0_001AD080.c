#include "common.h"

void ItemObj_DrawPass_1_001ACEB0(void (*f)(void));
void ItemObj_FilterTranslucent_0_001AD030(void);
void ItemObj_FilterOpaque_0_001ACFE0(void);
void Mdl_FlushLayer_0_0016B280(void);

void ItemObj_Draw_0_001AD080(void)
{
    ItemObj_DrawPass_1_001ACEB0(ItemObj_FilterTranslucent_0_001AD030);
    ItemObj_DrawPass_1_001ACEB0(ItemObj_FilterOpaque_0_001ACFE0);
    Mdl_FlushLayer_0_0016B280();
}

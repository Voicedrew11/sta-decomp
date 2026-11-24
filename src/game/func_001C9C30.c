#include "m2c.h"
M2C_UNK func_00123C40(M2C_UNK *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_00128580(s32, s32);                    /* extern */
s8 **func_001A5970(s8 *);                         /* extern */
extern s32 D_00202278;
extern s8 *D_002022E4;
extern M2C_UNK D_004B4BE0[];

void func_001C9C30(void) {
    s8 *temp_s0;

    if (D_002022E4 != NULL) {
        temp_s0 = (signed char *)(M2C_FIELD(D_002022E4, s32 *, 0x518) + 0x180);
        func_00123C40(D_004B4BE0, 0, 0x58);
        func_00177570(M2C_FIELD(temp_s0, s8 **, 0x448));
        func_00177570(M2C_FIELD(temp_s0, s8 **, 0x44C));
        func_00177570(M2C_FIELD(temp_s0, s8 **, 0x3B0));
        func_00177570(M2C_FIELD(temp_s0, s8 **, 0x3B4));
        func_00177570(M2C_FIELD(temp_s0, s8 **, 0x450));
        func_00128580(D_00202278, M2C_FIELD(temp_s0, s32 *, 0x3A8));
        func_001A6A10(func_001A5970(D_002022E4));
        D_002022E4 = NULL;
    }
    func_001CAE90();
}

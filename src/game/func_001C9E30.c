#include "common.h"
typedef struct { char pad[0x25]; unsigned char : 1; unsigned char f : 1; } BF_25_1_1;
void func_001CEA50(s32);                     /* extern */
extern void *D_002022E4;

void func_001C9E30(void) {
    void **temp_3;
    void *temp_5;

    func_001A6C90(D_002022E4);
    temp_3 = M2C_FIELD(M2C_FIELD(D_002022E4, void **, 0x518), void ***, 0xB0);
    if ((temp_3 != NULL) || (*temp_3 != NULL)) {
        temp_5 = *temp_3;
        ((BF_25_1_1 *)temp_5)->f = 1;
    }
    func_001CEDC0(3);
    func_001CEA50(1);
}

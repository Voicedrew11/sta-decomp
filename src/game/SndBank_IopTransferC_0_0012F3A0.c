#include "m2c.h"
typedef struct { s32 a; u32 size; s32 b; s32 c; s8 data[1]; } H;
void FlushCache(s32);
void memcpy(void *, s8 *, u32);
s32 Se_UploadBankB_1_001DB510(s8, void *, u32);
s8 Se_FindFreeSlot_0_001DB6B0(void);
extern s8 D_0022EBC0[];
extern s32 D_0022F080[];
extern s32 D_0022F084[];
extern u32 D_0022F088[];
extern u32 D_0022F08C[];
extern u8 D_0022F090[];

s32 SndBank_IopTransferC_0_0012F3A0(H *arg0, u32 arg1) {
    s32 r = -1;
    s32 ret;
    s8 *p;
    switch (D_0022F084[0]) {
    case 0:
        if (arg1 >= 4) break;
        p = &D_0022EBC0[arg1];
        *p = Se_FindFreeSlot_0_001DB6B0();
        if (*p == -1) break;
        if (arg0->size > 0x40000) break;
        D_0022F08C[0] = arg0->size;
        D_0022F084[0] = 1;
        D_0022F080[0] = 0;
        D_0022F088[0] = 0;
    case 1:
        { s8 *p = (s8 *)((s32)arg0->data + ((arg0->c + 0xF) & ~0xF)); D_0022F088[0] = D_0022F08C[0]; memcpy(D_0022F090, p, D_0022F088[0]); }
        FlushCache(0);
        D_0022F084[0] = 2;
    case 2:
        ret = Se_UploadBankB_1_001DB510(D_0022EBC0[arg1], D_0022F090, D_0022F088[0]);
        if (ret == 1) {
            D_0022F084[0] = 3;
            goto st3;
        }
        if (ret == 0) {
            r = 0;
            break;
        }
        D_0022F084[0] = 0;
        break;
    case 3:
    st3:
        D_0022F084[0] = 0;
        r = 1;
        break;
    default:
        D_0022F084[0] = 0;
        break;
    }
    FlushCache(0);
    return r;
}

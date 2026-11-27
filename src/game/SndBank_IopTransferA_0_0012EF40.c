#include "m2c.h"
void FlushCache(s32);
void memcpy(u8 *, s8 *, u32);
s32 Se_UploadBank_1_001DAA90(s8, u8 *, u32);
s8 Se_FindFreeBank_0_001DAC30(void);
typedef struct { s32 a; u32 size; s32 b; s32 c; s8 data[]; } H;
extern s8 D_0022EBC8[];
extern s32 D_0022F080[];
extern s32 D_0022F084[];
extern u32 D_0022F088[];
extern u32 D_0022F08C[];
extern u8 D_0022F090[];

s32 SndBank_IopTransferA_0_0012EF40(H *arg0, u32 arg1) {
    s32 ret;
    s32 r;
    s8 *p;
    s8 *q;

    ret = -1;
    switch (D_0022F084[0]) {
    case 0:
        if (arg1 >= 4) break;
        p = &D_0022EBC8[arg1];
        *p = Se_FindFreeBank_0_001DAC30();
        if (*p == -1) break;
        if (arg0->size > 0x40000) break;
        D_0022F08C[0] = arg0->size;
        D_0022F084[0] = 1;
        D_0022F080[0] = 0;
        D_0022F088[0] = 0;
    case 1:
        q = (s8 *)((s32)arg0->data + ((arg0->c + 0xF) & ~0xF));
        D_0022F088[0] = D_0022F08C[0];
        memcpy(D_0022F090, q, D_0022F088[0]);
        FlushCache(0);
        D_0022F084[0] = 2;
    case 2:
        r = Se_UploadBank_1_001DAA90(D_0022EBC8[arg1], D_0022F090, D_0022F088[0]);
        if (r == 1) {
            D_0022F084[0] = 3;
        } else if (r == 0) {
            ret = 0;
            break;
        } else {
            D_0022F084[0] = 0;
            break;
        }
    case 3:
        D_0022F084[0] = 0;
        ret = 1;
        break;
    default:
        D_0022F084[0] = 0;
        break;
    }
    FlushCache(0);
    return ret;
}

#include "m2c.h"
typedef union { u64 d[2]; u128 q; } T;
#define SET_PRIM(prim, iip, tme, fge, abe, aa1, fst, ctxt, fix) \
    ((u64)(prim) | ((u64)(iip) << 3) | ((u64)(tme) << 4) | ((u64)(fge) << 5) | ((u64)(abe) << 6) | \
     ((u64)(aa1) << 7) | ((u64)(fst) << 8) | ((u64)(ctxt) << 9) | ((u64)(fix) << 10))
#define SET_TAG(nloop, eop, pre, prim, flg, nreg) \
    ((u64)(nloop) | ((u64)(eop) << 15) | ((u64)(pre) << 46) | ((u64)(prim) << 47) | ((u64)(flg) << 58) | \
     ((u64)(nreg) << 60))
extern s32 D_00201F48;
extern s32 D_00201FEC;
extern s32 D_00202008;
extern T D_0042D8C0[][2];
extern T D_0042DDC0[][2];

void TexAnim_InitTables_0_001746A0(void) {
    T t;
    s32 i;
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    s32 e;
    s32 aa1;
    s32 abe;
    u32 prim;

    if (D_00201FEC == 0) {
        t.d[1] = 0x412;
        for (i = 0; i < 40; i++) {
            for (a = 0; a < 2; a++) {
                for (b = 0; b < 2; b++) {
                    for (c = 0; c < 2; c++) {
                        for (d = 0; d < 2; d++) {
                            for (e = 0; e < 2; e++) {
                                aa1 = e;
                                abe = d;
                                if (d) {
                                    aa1 = 0;
                                }
                                if (aa1) {
                                    abe = 1;
                                }
                                prim = SET_PRIM(4, a, b, c, abe, aa1, 0, 0, 0);
                                t.d[0] = SET_TAG(i, 1, 1, prim, 0, 3);
                                D_0042DDC0[(i << 5) | (a << 4) | (b << 3) | (c << 2) | (d << 1) | e][0] = t;
                                prim = SET_PRIM(5, a, b, c, abe, aa1, 0, 0, 0);
                                t.d[0] = SET_TAG(i, 1, 1, prim, 0, 3);
                                D_0042DDC0[(i << 5) | (a << 4) | (b << 3) | (c << 2) | (d << 1) | e][1] = t;
                            }
                        }
                    }
                }
            }
            t.d[0] = SET_TAG(i, 1, 1, 0x25C, 0, 3);
            D_0042D8C0[i][0] = t;
            t.d[0] = SET_TAG(i, 1, 1, 0x25D, 0, 3);
            D_0042D8C0[i][1] = t;
        }
        D_00201FEC = 1;
        D_00202008 = D_00201F48;
    }
}

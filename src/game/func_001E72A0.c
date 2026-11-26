#include "common.h"
void func_001D6910(s32, s32);
s32 func_001D6958(u32 a, u32 b, char *c, s32 d, s32 e, s32 *f);
s32 func_001D6A18(u32 a, u32 b, s32 c, s32 d, s32 e);
s32 func_001D6E48(s32, s32);
s32 func_001D7008(s32, s32);
s32 func_001D7098(void);
s32 func_001D70A8(void);
void func_001E8310(s32 idx, s32 *pa, s32 *pb);
s32 sprintf(char *, const char *, ...);
extern char D_00201760[];
extern char D_00201770[];
extern char D_00201780[];
extern char D_00201798[];
extern char D_002017A8[];
extern char D_002017B8[];
extern s32 D_002023B4;
extern s32 D_002023BC;
extern s32 D_002023CC;
extern s32 D_002023D0;
extern s32 D_002023D4;
extern s32 D_002023D8;
extern s32 D_002023E0;
extern s32 D_002023E4;
extern s32 D_004BC380[];
extern s32 D_004BC384[];
extern s32 D_004BC388[];
extern s32 D_004BC38C[];
extern s32 D_004BC394[];
extern s32 D_004BC39C[];
extern s32 D_004BC3A0[];
extern s32 D_004BC740[];
extern char D_004BCB80[];
extern s32 D_004BCBC0[];

static inline s32 retry(s32 r) {
    s32 s = D_002023D8;
    if (r != 0) {
        if (++D_002023B4 >= 5) {
            return 2;
        }
        return 1;
    }
    D_002023D8 = s + 1;
    D_002023B4 = 0;
    return 0;
}

void func_001E72A0(s32 arg0) {
    s32 r;
    s32 t;
    s32 i;

    switch (D_002023D8) {
    case 0:
        func_001D6910(D_002023E4, D_002023E0);
        D_002023D8++;
        break;
    case 1:
        r = func_001D6E48(D_002023E4, 0);
        if (r < 0) {
            t = D_002023E4 << 8;
            D_004BC384[t] = 0;
            D_004BC388[t] = 0;
        } else if (r == 2) {
            t = D_002023E4 << 8;
            D_004BC384[t] = 1;
            D_004BC388[t] = 0;
        }
        if (r == 0) {
            t = D_002023E4 << 8;
            D_004BC384[t] = 1;
            D_004BC388[t] = 1;
        } else {
            t = D_002023E4 << 8;
            D_004BC384[t] = 0;
            D_004BC388[t] = 0;
        }
        D_004BC394[t] = func_001D7008(D_002023E4, D_002023E0);
        D_004BC380[t] = 1;
        if (*(s32 *)((s32)D_004BC388 + t * 4) == 0) {
            D_002023D8 = -1;
            D_004BC39C[t] = 1;
        } else {
            D_002023D8++;
        }
        break;
    case 2:
        if (retry(func_001D6958(D_002023E4, D_002023E0, D_00201760, 0, 0xE, D_004BCBC0)) == 2) {
            D_002023D8 = -1;
            D_004BC39C[D_002023E4 << 8] = 1;
        }
        break;
    case 3:
        r = func_001D7098() > 0;
        D_004BC38C[D_002023E4 << 8] = r;
        sprintf(D_004BCB80, D_00201770, D_00201760, r);
        D_002023D8++;
        break;
    case 4:
        if (retry(func_001D6958(D_002023E4, D_002023E0, D_004BCB80, 0, 0xE, (s32 *)((s32)&D_004BC380[D_002023E4 << 8] + 0x40))) == 2) {
            D_002023D8 = -1;
            D_004BC39C[D_002023E4 << 8] = 1;
        }
        break;
    case 5:
        func_001D70A8();
        i = D_002023E4;
        t = i << 8;
        D_004BC3A0[t] = func_001D7098();
        func_001E8310(i, &D_002023BC, (s32 *)((s32)&D_004BC380[t] + 0x3C4));
        t = D_002023E4 << 8;
        D_004BC740[t] = D_002023BC;
        if ((D_002023D4 < 0 ? (D_002023BC & 8) != 0 : (D_002023BC & (1 << (D_002023D4 + 4))) != 0) == 0) {
            D_002023D8 = -1;
            D_004BC39C[t] = 1;
            break;
        }
        if (D_002023D4 < 0) {
            sprintf(D_004BCB80, D_00201780, D_00201760, D_00201798, D_002023D4);
        } else {
            sprintf(D_004BCB80, D_002017A8, D_00201760, D_002017B8, D_002023D4);
        }
        D_002023D8++;
        break;
    case 6:
        r = *(volatile s32 *)&D_002023CC;
        if (retry(func_001D6A18(D_002023E4, D_002023E0, (s32)D_004BCB80, D_002023D0, r)) == 2) {
            D_002023D8 = -1;
            D_004BC39C[D_002023E4 << 8] = 1;
        }
        break;
    case 7:
        r = func_001D70A8();
        if (r == 0x64) {
            D_002023D8 = -1;
            D_004BC39C[D_002023E4 << 8] = 1;
        } else if (r == 1) {
            t = D_002023E4 << 8;
            D_004BC384[t] = 0;
            D_002023D8 = -1;
            D_004BC39C[t] = 1;
        } else if (arg0 != 0) {
            D_002023D8 = -1;
            D_004BC39C[D_002023E4 << 8] = 1;
        } else {
            D_004BC39C[D_002023E4 << 8] = 0;
            D_002023D8 = -1;
        }
        break;
    }
}

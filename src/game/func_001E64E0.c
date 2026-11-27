#include "common.h"
void func_001E64E0(s32 arg0);
void func_001E72A0(s32 arg0);

/* func_001E64E0 */
void func_001D6910(s32, s32);
s32 func_001D6958(s32, s32, char*, s32, s32, void *);
s32 func_001D69B0(s32, s32, char *, s32, u32);
void func_001D6A80(s32, s32, char *, void *, u32);
void func_001D6C60(s32, s32, char *);
s32 func_001D6D00(void);
s32 func_001D6E48(s32, s32);
s32 func_001D7008(s32, s32);
s32 func_001D7098(void);
s32 func_001D70A8(void);
void func_001E8310(s32, void *, void *);
s32 sprintf(char *, const char *, ...);
s32 strlen(const char *);
s32 strncmp(const u8 *, const char *, s32);
extern char D_00201760[];
extern char D_00201770[];
extern char D_00201778[];
extern char D_00201780[];
extern char D_00201788[];
extern char D_00201798[];
extern char D_002017A8[];
extern char D_002017B8[];
extern char D_002017C8[];
extern s32 D_002023B4;
extern s32 D_002023C0;
extern s32 D_002023C4;
extern s32 D_002023C8;
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
extern u8 D_004BCBC0[];
extern u8 D_004BCF40[];

typedef struct { u8 p0[0x10]; s32 x10; u8 p14[0xC]; u8 name[0x20]; } E;

#define FAIL() { D_002023D8 = -1; D_004BC39C[D_002023E4 << 8] = 1; }

static inline s32 chk(s32 r) {
    s32 s = D_002023D8;
    if (r != 0) {
        if (!(++D_002023B4 < 5)) return 2;
        return 1;
    }
    D_002023D8 = s + 1;
    D_002023B4 = 0;
    return 0;
}

static inline void clean(void) {
    s32 len;
    s32 d;
    s32 i;
    s32 n;
    E *e;
    d = D_002023D4;
    e = (E *)((u8 *)&D_004BC380[D_002023E4 << 8] + 0x40);
    n = D_004BC3A0[D_002023E4 << 8];
    for (i = 2; i < n; i++) {
        s32 c;
        len = strlen(D_002017B8);
        if (strncmp(e[i].name, D_002017B8, len) == 0) {
            c = e[i].name[len] - '0';
            if (c == d) e[i].x10 = 0;
        }
    }
    func_001E8310(D_002023E4, (u8 *)&D_004BC380[D_002023E4 << 8] + 0x3C0, (u8 *)&D_004BC380[D_002023E4 << 8] + 0x3C4);
}

void func_001E64E0(s32 arg0) {
    s32 r;
    s32 e;
    s32 r2;
    s32 f, f4;

    switch (D_002023D8) {
    case 0:
        func_001D6910(D_002023E4, D_002023E0);
        D_002023D8++;
        break;
    case 1:
        r = func_001D6E48(D_002023E4, 0);
        if (r < 0) {
            D_004BC384[D_002023E4 << 8] = 0;
            D_004BC388[D_002023E4 << 8] = 0;
        } else if (r == 2) {
            D_004BC384[D_002023E4 << 8] = 1;
            D_004BC388[D_002023E4 << 8] = 0;
        }
        if (r == 0) {
            D_004BC384[D_002023E4 << 8] = 1;
            r2 = func_001D70A8();
            D_004BC388[D_002023E4 << 8] = 1;
            switch (r2) {
            case 3:
                D_004BC388[D_002023E4 << 8] = 0;
                break;
            }
        } else {
            D_004BC384[D_002023E4 << 8] = 0;
            D_004BC388[D_002023E4 << 8] = 0;
        }
        e = *(volatile s32 *)&D_002023E4 << 8;
        D_004BC394[e] = func_001D7008(D_002023E4, D_002023E0);
        D_004BC380[e] = 1;
        if (D_004BC388[e] == 0) {
            D_002023D8 = -1;
            D_004BC39C[e] = 1;
            return;
        }
        D_002023D8++;
        break;
    case 2:
        if (chk(func_001D6958(D_002023E4, D_002023E0, D_00201760, 0, 0xE, D_004BCBC0)) == 2) {
            FAIL();
            return;
        }
        break;
    case 3:
        r = func_001D7098() > 0;
        D_004BC38C[D_002023E4 << 8] = r;
        if (r) {
            sprintf(D_004BCB80, D_00201770, D_00201760);
            D_002023D8 = 8;
        } else {
            sprintf(D_004BCB80, D_00201778, D_00201760);
            func_001D6C60(D_002023E4, D_002023E0, D_004BCB80);
            D_002023D8++;
        }
        break;
    case 4:
        if (func_001D70A8() == 0x64) {
            FAIL();
            return;
        }
        if (arg0 != 0) {
            FAIL();
            return;
        }
        D_004BC38C[D_002023E4 << 8] = 1;
        sprintf(D_004BCB80, D_00201770, D_00201760);
        D_002023D8++;
        break;
    case 5:
        if (chk(func_001D6958(D_002023E4, D_002023E0, D_004BCB80, 0, 0xE, (u8 *)&D_004BC380[D_002023E4 << 8] + 0x40)) == 2) {
            FAIL();
            return;
        }
        break;
    case 6:
        if (func_001D70A8() == 0x64) {
            FAIL();
            return;
        }
        if (arg0 != 0) {
            FAIL();
            return;
        }
        e = D_002023E4;
        D_004BC3A0[e << 8] = func_001D7098();
        func_001E8310(e, &D_002023C0, (u8 *)&D_004BC380[e << 8] + 0x3C4);
        D_004BC740[D_002023E4 << 8] = D_002023C0;
        D_002023D8++;
    case 7:
        f4 = D_002023C0 & 4;
        if (!(D_002023C0 & 1)) {
            sprintf(D_004BCB80, D_00201780, D_00201760, D_00201760);
            func_001D69B0(D_002023E4, D_002023E0, D_004BCB80, 0, 0);
            while (0 < (r = func_001D6D00())) {}
            if (r < 0) {
                FAIL();
                return;
            }
            D_002023C0 |= 1;
            return;
        }
        if (!f4) {
            sprintf(D_004BCB80, D_00201780, D_00201760, D_00201788);
            func_001D6A80(D_002023E4, D_002023E0, D_004BCB80, (void *)D_002023C8, D_002023C4);
            while (0 < (r = func_001D6D00())) {}
            if (r < 0) {
                FAIL();
                return;
            }
            D_002023C0 |= 4;
            return;
        }
        D_002023D8++;
        break;
    case 8:
        if (D_002023D4 < 0) {
            sprintf(D_004BCB80, D_00201780, D_00201760, D_00201798, D_002023D4);
        } else {
            sprintf(D_004BCB80, D_002017A8, D_00201760, D_002017B8, D_002023D4);
        }
        D_002023D8++;
    case 9:
        if (chk(func_001D69B0(D_002023E4, D_002023E0, D_004BCB80, D_002023D0, D_002023CC)) == 2) {
            FAIL();
            return;
        }
        break;
    case 10:
        r = func_001D70A8();
        if (r != 0x3E) {
            FAIL();
        }
        if (r == 0x64) {
            clean();
            FAIL();
            return;
        }
        if (arg0 != 0) {
            clean();
            FAIL();
            return;
        }
        sprintf(D_004BCB80, D_00201770, D_00201760);
        D_002023D8++;
        break;
    case 11:
        if (chk(func_001D6958(D_002023E4, D_002023E0, D_004BCB80, 0, 0xE, (u8 *)&D_004BC380[D_002023E4 << 8] + 0x40)) == 2) {
            FAIL();
            return;
        }
        break;
    case 12:
        if (!(D_002023C0 & 2)) {
            sprintf(D_004BCB80, D_002017C8, D_00201760);
            func_001D6A80(D_002023E4, D_002023E0, D_004BCB80, D_004BCF40, 0x3C4);
            while (0 < (r = func_001D6D00())) {}
            if (r < 0) {
                FAIL();
                return;
            }
            D_002023C0 |= 2;
            return;
        }
        D_002023D8++;
        break;
    case 13:
        f = func_001D70A8();
        e = D_002023E4;
        D_004BC394[e << 8] = func_001D7008(e, D_002023E0);
        D_004BC3A0[e << 8] = func_001D7098();
        func_001E8310(e, (u8 *)&D_004BC380[e << 8] + 0x3C0, (u8 *)&D_004BC380[e << 8] + 0x3C4);
        if (f == 0x64) {
            clean();
            FAIL();
            return;
        }
        if (arg0 != 0) {
            clean();
            FAIL();
            return;
        }
        D_004BC39C[D_002023E4 << 8] = 0;
        D_002023D8 = -1;
        break;
    }
}

/* func_001E72A0 */
void func_001D6910(s32, s32);
s32 func_001D6958(s32, s32, char*, s32, s32, void *);
s32 func_001D6A18(u32 a, u32 b, s32 c, s32 d, s32 e);
s32 func_001D6E48(s32, s32);
s32 func_001D7008(s32, s32);
s32 func_001D7098(void);
s32 func_001D70A8(void);
void func_001E8310(s32, void *, void *);
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
extern u8 D_004BCBC0[];

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

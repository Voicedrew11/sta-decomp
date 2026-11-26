#include "m2c.h"
extern s32 *D_002020DC;
extern s32 D_0049F8A0[];
extern s32 D_0049F8E0[];
extern s32 D_0049FAE4[];
extern u32 D_0049FAE8[];
extern s32 D_0049FAEC[];
extern s32 D_0049FAF0[];
extern s32 D_0049FD40[];
extern s32 D_0049FF90[];
extern s32 D_004A01E0[];
extern s32 D_004A0220[];
extern s32 D_004A0424[];
extern u32 D_004A0428[];
extern s32 D_004A042C[];
extern s32 D_004A0430[];
extern s32 D_004A0470[];
extern s32 D_004A0674[];
extern u32 D_004A0678[];
extern s32 D_004A067C[];
extern s32 D_004A0680[];
void func_00159DD0(s32, s32 *, s32 *, s32 *);
void func_00189D50(s32, s32 *, s32);
void func_00189740(s32 *, u64);
void func_00182990(s32 *);
void func_0018A410(s32 *);
void func_0018AEA0(s32 *);
void func_00180F40(void);
void func_001E1760(s32 *);

void func_00189AD0(s32 *arg0) {
    s32 a; s32 b; s32 c; s32 d; s32 e; s32 f;
    u32 i; s32 *p; s32 *r; s32 *q; u32 j;
    D_002020DC = arg0;
    func_00189740(D_0049F8A0, 0x13BCC6E4);
    a = 0; b = 0;
    func_00159DD0(0x13BD5472, D_002020DC, &a, &b);
    i = 0; if (i < D_0049FAE8[0]) { p = D_0049F8A0; do { func_00189D50(p[0], D_0049F8E0, a); i++; p++; } while (i < D_0049FAE8[0]); }
    D_0049FAE4[0] = a; D_0049FAEC[0] = b;
    func_00189740(D_004A0430, 0x9D2D9756);
    c = 0; d = 0;
    func_00159DD0(0x9D2C05C0, D_002020DC, &c, &d);
    j = 0; if (j < D_004A0678[0]) { r = D_0049F8A0; q = D_004A0470; do { func_00189D50(r[0x2E4], q, c); j++; r++; } while (j < D_004A0678[0]); }
    D_004A0674[0] = c; D_004A067C[0] = d;
    func_00189740(D_004A01E0, 0x0178F67D);
    e = 0; f = 0;
    func_00159DD0(0x017964EB, D_002020DC, &e, &f);
    j = 0; if (j < D_004A0428[0]) { r = D_0049F8A0; q = D_004A0220; do { func_00189D50(r[0x250], q, e); j++; r++; } while (j < D_004A0428[0]); }
    D_004A0424[0] = e; D_004A042C[0] = f;
    func_00189740(D_0049FD40, 0x0EBDF3D7);
    func_00189740(D_0049FAF0, 0xF733968B);
    func_00189740(D_004A0680, 0x90BD8B46);
    func_00189740(D_0049FF90, 0x45E9E286);
    func_00182990(D_002020DC);
    func_0018A410(D_002020DC);
    func_0018AEA0(D_002020DC);
    func_00180F40();
    func_001E1760(D_002020DC);
}

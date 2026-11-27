#include "m2c.h"
#include "common.h"
#include "actor.h"
typedef struct { u64 FBP:9; u64 p0:7; u64 FBW:6; u64 p1:2; u64 PSM:6; u64 p2:2; u64 FBMSK:32; } GsFrame;
typedef struct { u64 ZBP:9; u64 p0:15; u64 PSM:4; u64 p1:4; u64 ZMSK:1; u64 p2:31; } GsZbuf;
typedef struct { u64 FBP:9; u64 FBW:6; u64 PSM:5; u64 p0:12; u64 DBX:11; u64 DBY:11; u64 p1:10; } GsDispfb;
typedef struct { u64 OFX:16; u64 p0:16; u64 OFY:16; u64 p1:16; } GsXy;
typedef struct { u64 PRIM:3; u64 IIP:1; u64 TME:1; u64 FGE:1; u64 ABE:1; u64 AA1:1; u64 FST:1; u64 CTXT:1; u64 FIX:1; u64 p0:53; } GsPrim;
typedef struct { u64 pmode; u64 smode2; GsDispfb dispfb; u64 display; u64 bgcolor; } DispEnv;
typedef struct {
    GsFrame frame1; u64 frame1addr;
    GsZbuf zbuf1; u64 zbuf1addr;
    GsXy xyoffset1; u64 xyoffset1addr;
    u64 scissor1; u64 scissor1addr;
    u64 prmodecont; u64 prmodecontaddr;
    u64 colclamp; u64 colclampaddr;
    u64 dthe; u64 dtheaddr;
    u64 test1; u64 test1addr;
} DrawEnv1;
typedef struct {
    u64 testa; u64 testaaddr;
    GsPrim prim; u64 primaddr;
    u64 rgbaq; u64 rgbaqaddr;
    u64 xyz2a; u64 xyz2aaddr;
    u64 xyz2b; u64 xyz2baddr;
    u64 testb; u64 testbaddr;
} Clear;
typedef struct { DispEnv disp[2]; u64 giftag0[2]; DrawEnv1 draw0; Clear clear0; u64 giftag1[2]; DrawEnv1 draw1; Clear clear1; } DBuff;
typedef f32 Mtx_func_001294A0[4][4];
typedef union { u128 q; Vec v; } VQ;
typedef struct {
    s16 m[16];
    f32 f20;
    union {
        u32 w;
        struct {
            u32 a:1; u32 b:1; u32 c:1; u32 d:1; u32 e:2; u32 f:2;
            u32 g:2; u32 h:2; u32 i:8; u32 rest:12;
        } bf;
    } u24;
    u64 x28;
    u64 x30;
    u8 pad[8];
} S;
typedef struct {
    s32 x0, x4, x8, xC, x10, x14, x18, x1C;
    s32 pad20[9];
    s32 x44;
    s32 x48;
    struct { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:5; } f4C;
    u8 pad4D[3];
} Buf;
typedef struct { u8 pad[0x1D8]; u8 f; } Inner;
typedef struct { s32 pad[4]; s32 x10; u8 x14; u8 pad15[3]; s32 *x18; s32 pad1C; } Info;
typedef struct { u8 a:3; u8 b:3; u8 c:2; } BF;
typedef struct {
    u8 x0;
    u8 x1;
    s16 x2;
    s16 x4;
    s16 x6;
    s16 x8;
    s16 xA;
    u8 padC[0x24];
    f32 x30;
    u8 pad34[4];
    f32 x38;
    u8 pad3C[4];
    Flags8 f40;
    Flags8 f41;
    Flags8 f42;
    Flags8 f43;
    Flags8 f44;
} G;
extern s32 D_00201C00;
extern s32 D_00201E80;
extern s32 D_00201F90;
extern s8 D_00222700[];
extern s8 *D_00222B50[];
extern s32 D_00222B70[];
extern s32 D_00222B74[];
extern s32 D_00222B78[];
extern s32 D_00222B7C[];
extern s32 D_00222B80[];
extern s32 D_00222B84[];
extern s32 D_00222B88[];
extern DBuff D_002F1390;
extern DBuff D_002F1160;
extern s32 D_00201F2C;
extern f32 D_001F2170[];
extern u64 D_00222A68[];
extern u64 D_00222A70[];
extern u64 D_00222A78[];
extern f32 D_00201C2C;
extern f32 D_00201EB4;
extern f32 D_00201C14;
extern f32 D_00201C18;
extern f32 D_00201C1C;
extern u32 D_00201C20;
extern u32 D_00201C24;
extern f32 D_00201E90;
extern f32 D_00222A40[];
extern f32 D_00222A44[];
extern s8 D_00222A11[];
extern VQ D_001F1BD0;
extern VQ D_001F1BE0;
extern s8 D_001F1BB0[];
extern u64 D_002F1420[];
extern u64 D_002F1510[];
extern Mtx D_002F1680;
extern f32 D_002F1690[];
extern f32 D_002F1694[];
extern f32 D_002F1698[];
extern Mtx D_002F16C0;
extern Mtx D_002F1700;
extern Mtx D_002F1740;
extern Mtx D_002F1780;
extern Mtx D_002F17C0;
extern Mtx D_002F1800;
extern Mtx D_002F1840;
extern Mtx D_002F1880;
extern Mtx D_002F18C0;
extern Mtx D_002F1900;
extern f32 D_001F1BC0[];
extern f32 D_001F1BC4[];
extern f32 D_001F1BC8[];
extern f32 D_001F1BCC[];
extern s32 D_00201C5C;
extern u8 D_00201EB8;
extern s32 D_00222A28[];
extern s32 D_00222A24[];
extern s32 D_00222A1C[];
extern s32 D_00222A20[];
extern s16 D_00222A12[];
extern Flags8 D_00222A52[];
extern s32 D_00222748[];
extern VQ D_001F1BF0;
extern VQ D_001F1C00;
extern s32 D_00222738[];
extern s32 D_0022273C[];
extern s32 D_00222740[];
extern s32 D_00222744[];
extern s32 D_00201EA8;
extern s8 D_00222AF0[];
extern s8 D_00222B20[];
extern s32 D_00201EA4;
extern s8 D_003139A0[];
extern s32 D_00201E94;
extern s32 D_00201C10;
extern s32 D_00201C34;
extern s32 D_00201EAC;
extern s32 D_00222A30[];
extern s32 D_00222A34[];
extern s32 D_00222A38[];
extern s32 D_00222A3C[];
extern s32 D_00222B5C[];
extern s32 D_00222B60[];
extern BF D_00222A54[];
extern s32 D_00201E98;
extern s32 D_00222A2C[];
extern s32 D_00222734[];
extern s32 D_00222730[];
extern s32 D_00222B58[];
extern u8 D_001FAB40[];
extern s32 D_00201C28;
extern s32 D_00201C30;
extern s32 D_00201E9C;
extern void *D_00222B68[];
void func_00128F10(void);
void func_00129030(void);
void func_00129040(void);
void func_00129400(s32 arg0, s32 arg1, s32 arg2);
void func_001294A0(Mtx_func_001294A0 m0, Mtx_func_001294A0 m1, Mtx_func_001294A0 m2, f32 a, f32 b, f32 c, f32 d, f32 e, f32 f, f32 g, f32 h, f32 i, f32 j, f32 k);
void func_001296C0(void);
void func_00129EE0(S *p);
void func_0012A070(void);
void func_0012A520(f32 dt);
void func_0012AA30(void);
void func_0012AB40(s32 arg0);
void func_0012AC00(s32 arg0);
void func_0012B120(s32 arg0);
s32 func_0012B350(void);
void func_0012B550(void);
void func_0012B600(void);
s32 func_0012B8E0(s32 arg0);
void func_0012BC80(void);
void func_0012BF40(void);
s32 memalign(s32, s32);
void func_001A83A0(s8 *);
void func_00128E80(s32 *);
void func_00178D20(void);
void func_00178C00(s32, u32);
void func_00128A60(s8 *, s8 *, s32, s32);
void func_001AFFA0(s8 *);
void func_001AFCA0(s8 *);
void func_00195C00(s8 *);
void sceGsResetGraph(s32, s32, s32, s32);
void sceGsSetDefDBuff(DBuff *, s32, s32, s32, s32, s32, s32);
void sceVu0CopyMatrix(void *, void *);
s32 func_00178870(char *a0, float f0, float f1, float f2);
void func_00178910(s32, s32);
void sceDevVif0Reset();
void sceSdRemoteInit();
void sceDevVu0Pause();
void sceDmaReset(s32);
void sceGsResetPath();
void sceMcInit();
void sceVu0UnitMatrix(Mtx_func_001294A0);
void sceVu0MulMatrix(Mtx_func_001294A0, Mtx_func_001294A0, Mtx_func_001294A0);
s32 func_001C9BF0(void);
void func_001C8F90(void *);
void sceVu0RotMatrixX(Mtx *, Mtx *, f32);
void sceVu0RotMatrixY(Mtx *, Mtx *, f32);
void sceVu0CameraMatrix(void *, void*, Vec*, Vec*);
f32 tanf(f32);
u64 __fixunssfdi(f32);
void memset(void *, s32, s32);
s32 func_001787A0(void);
void func_00154B70(void);
void func_001741D0(void);
void func_00176A60(void);
void func_00175BB0(void);
void func_00164350(void);
void func_001547F0(s32, s32);
void func_00154B00(void *);
void func_001545D0(void);
void func_001543E0(s32, s64);
void func_00154420(void);
void func_0015B270(void);
void func_001549D0(void);
void func_00155900(void);
void func_00153740(void);
void func_001544C0(void);
void func_00155BD0(void *);
void func_00154700(s32, s32);
void func_001548F0(s32);
void func_001B3FD0(s32);
void func_001A6770(void);
void func_001BCFF0(void *);
void func_001AD080(void);
void func_001541E0(f32);
void func_00168A40(void);
void func_00159680(void);
s32 func_0019A790(void);
void func_001BCB60(void);
void func_00188F70(void);
void func_00187B20(s32);
void func_00171260(void);
void func_00154AF0(void);
void func_00176A40(void);
void func_00164330(void);
void func_00175B40(void);
void func_001B4F20(Inner *);
void func_001B4B50(Inner *, f32);
void func_001B4AF0(Inner *);
void func_001ADD30(void);
void func_001A6950(void);
void func_0012D650(void);
s32 func_0012C7C0();
void func_001B4CB0(void);
void func_0015D650(void);
void func_0015BB40(void *, void *, f32);
s32 func_001C9B50(void);
void func_0015B360(void *, s32);
void func_001B7290(void);
void func_0015C0C0(void *);
void func_0013BBC0(f32);
void func_001BC0E0(void);
void func_001ADA30(f32);
void func_0015D300(void);
void func_00169400(f32);
void func_00159970(f32);
void func_00175B10(f32);
void func_00159310(s32);
void func_001601C0(s32);
u8 func_001A9490(void);
void func_0015FEB0(s32, f32);
u8 func_001A94A0(void);
void func_0013BB70(void);
void func_001AD390(void);
void func_00169630(void);
void func_00188F80(void);
void func_00128210(void *);
void func_00128460(M2C_UNK *, M2C_UNK);
void func_00153B50(M2C_UNK);
void func_001552A0(void);
void func_00155370(void);
void func_00169780(void);
void func_00169790(void);
void func_00189580(void);
void func_0018A350(u8);
void func_00178760(void);
void func_001769C0(void);
void func_0015FC10(void);
void func_001A7D90(s32);
void func_001C9E30(void);
void func_001A8E30(void);
void func_001B06E0(s32, void *, s32);
void func_001B0660(Info *);
void func_001B0450(void);
void func_001B7380(s32, s32);
void func_001B7190(s32, s32);
u8 func_001AA740(void);
void func_001C96F0(s32);
void func_001AA700(s32);
void func_001E1CC0(void);
void func_001E1D30(s32, s32);
s32 func_001E1D20(void);
void func_0012C1A0(s32);
void func_0012F9D0(s32);
void func_0012F6E0(s32);
void func_0012C430(void);
void func_0019A840(void);
void func_00175C80(void);
void func_001643B0(void);
void func_0015DD90(void);
void func_0015BCA0(void);
void func_0015C8D0(void);
void func_00159A60(void);
void func_00159400(f32, void *);
s32 func_00159650(s32);
s32 func_00159620(s32);
s32 func_001595C0(s32);
s32 func_00159590(s32);
void func_001595F0(s32);
void func_00181240(void);
void func_00160300(void);
void func_00174620(void *, void *);
void func_0016AD10(s32, s32, s32);
void func_0016AB50(void);
void func_001B7470(void *, s32);
void func_001A82B0(void *, s32);
void func_001AF970(void *, s32);
void func_001AB290(s32);
u8 func_001AA750(void);
u8 func_001A9470(void);
u8 func_001A9480(void);
u8 func_001A9460(void);
void func_0012C6C0(s32);
void func_0012C730(s32);
void func_0012DA60(s32);
s32 func_00154AC0(void);
void func_001E8500(void);
void func_001C9830(void);
void func_001B4100(Inner *);
s32 sceCdSync(s32);
void func_001DF9A0(void);
void func_00180F80(void);
void func_001891C0(void);
void func_0015FC60(void);
void func_00160350(void);
void func_001787F0(void);
void func_00178DB0(void);
void func_00128D10(void);
void func_00155460(s32, s32);
void func_0014DB60(void);
void func_001B07B0(void);
void func_001A5340(void);
void func_001AF980(void);
void func_001E1770(void);
void func_001E1D70(void);
void func_001781A0(s32, s32);
void func_00188830(void *);
void func_001AB280();

/* .bss from 0x00222750, defined from the top down (CodeWarrior writes
   uninitialised objects in reverse order) */
s8 D_00222A80[0x70];
u64 D_00222A60[0x4];      /* also D_00222A68, D_00222A70, D_00222A78 */
u8 D_00222A50[0x10];
s8 D_00222A10[0x40];      /* also D_00222A14, D_00222A18, D_00222A1C, D_00222A20, D_00222A24, D_00222A28, D_00222A2C, D_00222A30, D_00222A34, D_00222A38, D_00222A3C, D_00222A40, D_00222A44, D_00222A48 */
Mtx D_002229D0;
Mtx D_00222990;
Mtx D_00222950;
Mtx D_00222910;
Mtx D_002228D0;
Mtx D_00222890;
f32 D_00222850[0x10];
s8 D_00222810[0x40];
s8 D_002227D0[0x40];
s8 D_00222790[0x40];
char D_00222750[0x40];

/* func_00128F10 */
void func_00128F10(void) {
    D_00201C00 = D_00201F90 - 0x40000;
    if (D_00201C00 > 0x06000000) {
        D_00201C00 = 0x06000000;
    }
    D_00201E80 = memalign(0x80, D_00201C00);
    func_00178D20();
    func_00178C00(D_00201E80, (u32)D_00201C00);
    D_00222B78[0] = 0x400000;
    D_00222B88[0] = 0x180000;
    D_00222B74[0] = 0x140000;
    D_00222B80[0] = 0x40000;
    D_00222B84[0] = 0x2C0000;
    D_00222B7C[0] = 0xF00000;
    D_00222B70[0] = 0x100000;
    func_00128E80(D_00222B70);
    func_00128A60(D_00222700, D_00222B50[0], D_00222B70[0], 0x80);
    func_001AFFA0(D_00222700);
    func_001AFCA0(D_00222700);
    func_00195C00(D_00222700);
    func_001A83A0(D_00222700);
}

/* func_00129030 */
void func_00129030(void) {
    func_0012DF90();
}

/* func_00129040 */
/* .bss, from the top down (CodeWarrior writes it in reverse) */
#define sceVu0CopyMatrix sceVu0CopyMatrix__as_func_00129040
void sceVu0CopyMatrix__as_func_00129040(f32 *, f32 *);

void func_00129040(void) {
    sceGsResetGraph(0, 1, 2, 0);
    sceGsSetDefDBuff(&D_002F1390, 0, 640, 448, 3, 0x3A, 1);
    D_002F1390.disp[0].dispfb.FBP = 0;
    D_002F1390.disp[1].dispfb.FBP = 0x8C;
    D_002F1390.draw0.frame1.FBP = 0x8C;
    D_002F1390.draw0.frame1.FBW = 10;
    D_002F1390.draw1.frame1.FBP = 0;
    D_002F1390.draw1.frame1.FBW = 10;
    D_002F1390.draw0.zbuf1.ZBP = 0x118;
    D_002F1390.draw1.zbuf1.ZBP = 0x118;
    sceVu0CopyMatrix(D_00222850, D_001F2170);
    func_00178870(D_00222750, 640.0f, 1.0f, 65536.0f);
    D_002F1390.clear1.rgbaq = D_002F1390.clear0.rgbaq = (u64)1 | ((u64)0xFF << 8) | ((u64)0xFF << 16) | ((u64)0 << 24) | ((u64)1 << 32);
    D_00201F2C = 0;
    sceGsSetDefDBuff(&D_002F1160, 0, 640, 448, 3, 0x3A, 1);
    D_002F1160.disp[0].dispfb.FBP = 0;
    D_002F1160.disp[1].dispfb.FBP = 0x8C;
    D_002F1160.draw0.frame1.FBP = 0x8C;
    D_002F1160.draw0.frame1.FBW = 10;
    D_002F1160.draw1.frame1.FBP = 0;
    D_002F1160.draw1.frame1.FBW = 10;
    D_002F1160.draw0.zbuf1.ZBP = 0x118;
    D_002F1160.draw1.zbuf1.ZBP = 0x118;
    D_002F1160.draw1.frame1addr = D_002F1160.draw0.frame1addr = 0x4D;
    D_002F1160.draw1.zbuf1addr = D_002F1160.draw0.zbuf1addr = 0x4F;
    D_002F1160.draw1.xyoffset1addr = D_002F1160.draw0.xyoffset1addr = 0x19;
    D_002F1160.draw1.scissor1addr = D_002F1160.draw0.scissor1addr = 0x41;
    D_002F1160.clear0.testbaddr = D_002F1160.clear0.testaaddr = D_002F1160.draw0.test1addr = 0x48;
    D_002F1160.clear1.testbaddr = D_002F1160.clear1.testaaddr = D_002F1160.draw1.test1addr = 0x48;
    D_002F1390.draw0.xyoffset1.OFX = D_002F1390.draw1.xyoffset1.OFX = D_002F1160.draw0.xyoffset1.OFX = D_002F1160.draw1.xyoffset1.OFX = 0x6C00;
    D_002F1390.draw0.xyoffset1.OFY = D_002F1390.draw1.xyoffset1.OFY = D_002F1160.draw0.xyoffset1.OFY = D_002F1160.draw1.xyoffset1.OFY = 0x7200;
    *(u32 *)&D_002F1160.clear0.prim |= 0x200;
    *(u32 *)&D_002F1160.clear1.prim |= 0x200;
    D_00222A70[0] = *(u64 *)&D_002F1390.disp[0].dispfb;
    D_00222A78[0] = *(u64 *)&D_002F1390.disp[1].dispfb;
    D_00222A60[0] = D_002F1390.disp[0].display;
    D_00222A68[0] = D_002F1390.disp[1].display;
    func_00178910(0, 0x4000);
}
#undef sceVu0CopyMatrix

/* func_00129400 */
void func_00129400(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_2;

    sceDevVif0Reset();
    sceDevVu0Pause();
    sceGsResetPath();
    sceDmaReset(1);
    temp_2 = *(s32 *)0x1000E000 | 0x303;
    *(s32 *)0x1000E000 = temp_2;
    *(s32 *)0x1000E000 = temp_2;
    func_0015CB50();
    func_0015AD00((s32 *) arg0, arg1, arg2);
    func_0015C9F0(-0x14CD88B5);
    sceMcInit();
    sceSdRemoteInit();
}

/* func_001294A0 */
void func_001294A0(Mtx_func_001294A0 m0, Mtx_func_001294A0 m1, Mtx_func_001294A0 m2, f32 a, f32 b, f32 c, f32 d, f32 e, f32 f, f32 g, f32 h, f32 i, f32 j, f32 k)
{
    Mtx_func_001294A0 t;
    f32 sx = j * f / a;
    f32 sy = j * g / a;
    f32 jk;

    sceVu0UnitMatrix(m0);
    m0[0][0] = a;
    m0[1][1] = a;
    m0[2][2] = 0.0f;
    m0[3][3] = 0.0f;
    m0[3][2] = 1.0f;
    m0[2][3] = 1.0f;
    sceVu0UnitMatrix(t);
    jk = k * j;
    t[2][2] = jk * (-h + i) / (-j + k);
    t[3][2] = (-i * j + h * k) / (-j + k);
    t[0][0] = b;
    t[1][1] = c;
    t[3][0] = d;
    t[3][1] = e;
    sceVu0MulMatrix(m0, t, m0);
    sceVu0UnitMatrix(m1);
    m1[0][0] = 2.0f * j / (sx + sx);
    m1[1][1] = 2.0f * j / (sy + sy);
    m1[2][2] = (k + j) / (k - j);
    m1[3][2] = -2.0f * jk / (k - j);
    m1[2][3] = 1.0f;
    m1[3][3] = 0.0f;
    sceVu0UnitMatrix(m2);
    m2[0][0] = sx * (a * b) / j;
    m2[1][1] = sy * (a * c) / j;
    m2[2][2] = (-i + h) / 2.0f;
    m2[3][2] = (i + h) / 2.0f;
    m2[3][0] = d;
    m2[3][1] = e;
    m2[3][3] = 1.0f;
}

/* func_001296C0 */
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)
#define sceVu0MulMatrix sceVu0MulMatrix__as_func_001296C0
void sceVu0MulMatrix__as_func_001296C0(void *, void *, void *);
#define func_001294A0 func_001294A0__as_func_001296C0
void func_001294A0__as_func_001296C0(void *m0, void *m1, void *m2, f32 a, f32 b, f32 c, f32 d, f32 e, f32 f, f32 g, f32 h, f32 i, f32 j, f32 k);
#define D_001F2170 D_001F2170__as_func_001296C0
extern Mtx D_001F2170__as_func_001296C0;
#define D_00222850 D_00222850__as_func_001296C0
extern Mtx D_00222850__as_func_001296C0;

void func_001296C0(void) {
    VQ a;
    VQ b;
    Mtx m;
    f32 fov;
    f32 s;
    s32 w;
    f32 k;

    fov = D_00222A40[0];
    switch (D_00222A11[0]) {
    case 0:
        a = D_001F1BD0;
        b = D_001F1BE0;
        sceVu0RotMatrixX(&m, &D_001F2170, WRAP(D_00201C2C));
        sceVu0RotMatrixY(&m, &m, WRAP(D_00201EB4));
        sceVu0CameraMatrix(&D_00222850, D_001F1BB0, &a.v, &b.v);
        sceVu0MulMatrix(&D_00222850, &D_00222850, &m);
        break;
    case 1:
        if (func_001C9BF0()) {
            func_001C8F90(&D_00222850);
        }
        break;
    }
    s = (D_00222A10[0] == 1) ? 0.622222245f : 1.0f;
    fov = 3.1415927f * fov / 360.0f;
    D_00201C14 = s * (128.0f * (1.0f / tanf(fov)));
    if (D_00222A10[0] == 1) {
        func_001294A0(&D_00222910, &D_002228D0, &D_00222890, D_00201C14, 1.42857146f, 2.22996521f, 2048.0f, 2048.0f, 650.0f, 564.0f, (f32)D_00201C20, (f32)D_00201C24, D_00201C18, D_00201C1C);
    } else {
        if (D_00222A10[0] == 2) {
            k = 1.56097567f;
            w = 616;
        } else {
            k = 1.42857146f;
            w = 616;
        }
        func_001294A0(&D_00222910, &D_002228D0, &D_00222890, D_00201C14, 1.0f, k, 2048.0f, 2048.0f, 929.0f, (f32)w, (f32)D_00201C20, (f32)D_00201C24, D_00201C18, D_00201C1C);
    }
    D_00201E90 = 0.0f;
    s = (D_00222A10[0] == 1) ? 1.24444449f : 1.0f;
    D_00201C14 = s * (320.0f * (1.0f / tanf(fov)));
    D_00222A44[0] = 0.933300018f;
    if (D_00222A10[0] == 1) {
        func_001294A0(&D_002229D0, &D_00222990, &D_00222950, D_00201C14, 0.803571403f, 1.0f, 2048.0f, 2048.0f, 1355.0f, 993.0f, (f32)D_00201C20, (f32)D_00201C24, D_00201C18, D_00201C1C);
        D_00222A44[0] = 1.01980102f;
    } else {
        func_001294A0(&D_002229D0, &D_00222990, &D_00222950, D_00201C14, 1.0f, 1.0f, 2048.0f, 2048.0f, 1089.0f, 993.0f, (f32)D_00201C20, (f32)D_00201C24, D_00201C18, D_00201C1C);
    }
    fov = D_00201E90;
    D_002F1510[0] = D_002F1420[0] = 0x27F0000 | ((u64)__fixunssfdi(fov) << 32) | ((u64)__fixunssfdi(448.0f - fov - 1.0f) << 48);
    sceVu0CopyMatrix(&D_002F18C0, &D_00222950);
    sceVu0CopyMatrix(&D_002F1900, &D_002229D0);
    sceVu0CopyMatrix(&D_002F1700, &D_00222990);
    sceVu0CopyMatrix(&D_002F16C0, &D_00222850);
    sceVu0MulMatrix(&D_002F1840, &D_002F1900, &D_002F16C0);
    sceVu0MulMatrix(&D_002F1880, &D_002F1700, &D_002F16C0);
    sceVu0CopyMatrix(&D_002F1780, &D_00222890);
    sceVu0CopyMatrix(&D_002F1740, &D_00222910);
    sceVu0CopyMatrix(&D_002F1680, &D_002F16C0);
    D_002F1690[0] *= -1.0f;
    D_002F1694[0] *= -1.0f;
    D_002F1698[0] *= -1.0f;
    sceVu0MulMatrix(&D_002F1800, &D_00222910, &D_002F1680);
    sceVu0MulMatrix(&D_002F17C0, &D_002228D0, &D_002F1680);
    D_001F1BCC[0] = 0.0f;
    D_001F1BC0[0] = 15000.0f;
    D_001F1BC4[0] = 32000.0f;
    D_001F1BC8[0] = 0.499999493f;
}
#undef sceVu0MulMatrix
#undef func_001294A0
#undef D_001F2170
#undef D_00222850

/* func_00129EE0 */
void func_00129EE0(S *p) {
    s32 z;
    memset(p, 0, 0x40);
    p->m[0] = 0x1000; p->m[1] = 0x1000; p->m[2] = 0x1000; p->m[3] = 0x1000;
    p->m[4] = 0x1000; p->m[5] = 0x1000; p->m[6] = 0x1000; p->m[7] = 0x1000;
    p->m[8] = 0x1000; p->m[9] = 0x1000; p->m[10] = 0x1000; p->m[11] = 0x1000;
    p->m[12] = 0x1000; p->m[13] = 0x1000; p->m[14] = 0x1000; p->m[15] = 0x1000;
    p->f20 = 1.0f;
    p->u24.w = 0;
    z = 0;
    p->u24.bf.a = 1;
    p->u24.bf.b = 1;
    p->u24.bf.c = z;
    p->u24.bf.d = z;
    p->u24.bf.e = z;
    p->u24.bf.f = 1;
    p->u24.bf.g = 2;
    p->u24.bf.h = 1;
    p->u24.bf.i = 0x80;
    p->x28 = -1;
    p->x30 = -1;
}

/* func_0012A070 */
#define D_002F1800 D_002F1800__as_func_0012A070
extern u8 D_002F1800__as_func_0012A070[];
#define D_002F1840 D_002F1840__as_func_0012A070
extern u8 D_002F1840__as_func_0012A070[];
#define D_002022E4 D_002022E4__as_func_0012A070
extern void *D_002022E4__as_func_0012A070;

void func_0012A070(void) {
    Buf b;
    s32 z;
    f32 d;
    s32 t;
    t = func_001787A0();
    func_00154B70();
    func_001741D0();
    func_00176A60();
    func_00175BB0();
    func_00164350();
    func_001547F0(0, 0);
    func_00154B00(D_002F1800);
    func_001545D0();
    func_001543E0(0x49, 0);
    func_001543E0(0x4C, 0x5015E);
    func_001543E0(0x40, 0x13F0000 | (s64)0xDF0000 << 32);
    func_001543E0(0x3B, 0x80 | (s64)0x80 << 32);
    func_001543E0(0x18, 0x7600 | (s64)0x7900 << 32);
    func_001543E0(0x4E, 0x3A000118);
    func_001543E0(0x47, 0x51000);
    func_00154420();
    func_0015B270();
    func_001549D0();
    func_00155900();
    func_001547F0(3, 0);
    func_00154B00(D_002F1840);
    func_00153740();
    memset(&b, 0, 0x50);
    z = 0;
    b.f4C.b0 = z;
    b.f4C.b1 = z;
    b.f4C.b2 = z;
    func_001545D0();
    func_001543E0(0x47, 0x30000);
    func_001544C0();
    b.x0 = 0x6C00;
    b.x8 = 0;
    b.x18 = 0;
    d = 224.0f - D_00201E90;
    b.x4 = (s32)(2048.0f - d) << 4;
    b.x10 = 0x9400;
    b.x44 = D_00201C5C;
    b.x14 = (s32)(2048.0f + d) << 4;
    func_00155BD0(&b);
    func_00155900();
    if (!D_00201EB8) {
        func_001548F0(0);
        func_001545D0();
        func_001543E0(0x47, 0x50000);
        func_001543E0(0x4E, 0x3A000118);
        func_001543E0(8, 0);
        func_001543E0(0x49, 0);
        func_001544C0();
        D_00222A28[0] = 0;
        D_00222A24[0] = 0;
        D_00222A1C[0] = 0;
        D_00222A20[0] = 0;
        if (D_00222A12[0]) {
            if ((&D_00201E80)[2]) func_001B3FD0(*((s32 **)&D_00201E80)[2]);
            if ((&D_00201E80)[3]) func_001B3FD0(*((s32 **)&D_00201E80)[3]);
        }
        func_001A6770();
        func_001BCFF0(D_002022E4);
        func_001AD080();
        func_001541E0(20000.0f);
        func_001548F0(4);
        func_001545D0();
        func_001543E0(0x47, 0x71011);
        func_001543E0(0x4E, 0x3A000118);
        func_001543E0(8, 0);
        func_001544C0();
        func_00168A40();
        func_00155900();
        func_00155900();
    }
    func_00159680();
    if (!func_0019A790() != 0) {

        D_00201EB8 = 1;
    } else {
        D_00201EB8 = 0;
    }
    func_00154700(5, 0);
    func_001BCB60();
    func_001545D0();
    func_001543E0(0x40, 0x27F0000 | (s64)0x1BF0000 << 32);
    func_001543E0(0x41, 0x27F0000 | (s64)0x1BF0000 << 32);
    func_001544C0();
    func_00155900();
    func_00154700(5, -2);
    func_001545D0();
    func_001543E0(0x40, 0x27F0000 | (s64)0x1BF0000 << 32);
    func_001543E0(0x41, 0x27F0000 | (s64)0x1BF0000 << 32);
    func_001543E0(0x49, 0);
    func_001544C0();
    if (!D_00222A52[0].f.b3) func_00188F70();
    func_00187B20(0);
    func_00155900();
    func_00171260();
    func_00154AF0();
    func_00176A40();
    func_00164330();
    func_00175B40();
    D_00222748[0] = func_001787A0() - t;
}
#undef D_002F1800
#undef D_002F1840
#undef D_002022E4

/* func_0012A520 */
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)
#define D_00201E80 D_00201E80__as_func_0012A520
extern Inner **D_00201E80__as_func_0012A520[2];
#define C (D_00201E80[2])
#define D (D_00201E80[3])
static inline s32 IS_func_0012A520(Inner **p) { if (p != NULL) return ((*p)->f & 1) != 0; else return 0; }
#define func_0012C7C0 func_0012C7C0__as_func_0012A520
void func_0012C7C0__as_func_0012A520(void);
#define sceVu0CameraMatrix sceVu0CameraMatrix__as_func_0012A520
void sceVu0CameraMatrix__as_func_0012A520(Mtx *, void *, Vec *, Vec *);
#define sceVu0MulMatrix sceVu0MulMatrix__as_func_0012A520
void sceVu0MulMatrix__as_func_0012A520(void *, void *, Mtx *);
#define D_002022E4 D_002022E4__as_func_0012A520
extern s8 *D_002022E4__as_func_0012A520;
#define D_00222A10 D_00222A10__as_func_0012A520
extern u8 D_00222A10__as_func_0012A520[];
#define D_001F2170 D_001F2170__as_func_0012A520
extern Mtx D_001F2170__as_func_0012A520;
#define D_002F1900 D_002F1900__as_func_0012A520
extern s8 D_002F1900__as_func_0012A520[];
#define D_002F1700 D_002F1700__as_func_0012A520
extern s8 D_002F1700__as_func_0012A520[];
#define D_002F16C0 D_002F16C0__as_func_0012A520
extern f32 D_002F16C0__as_func_0012A520[];

void func_0012A520(f32 dt) {
    Mtx v;
    VQ a;
    VQ b;
    Mtx m;
    s32 t;

    if (C) func_001B4F20(*C);
    if (D) func_001B4F20(*D);
    func_001ADD30();
    func_001A6950();
    func_0012D650();
    func_0012C7C0();
    func_001B4CB0();
    if (!(func_0019A790() != 0) == 0) {
        t = func_001787A0();
        if (IS_func_0012A520(C)) func_001B4B50(*C, dt);
        if (IS_func_0012A520(D)) func_001B4B50(*D, dt);
        D_00222738[0] = func_001787A0() - t;
        func_0015D650();
        if (D_002022E4) func_0015BB40(D_002022E4 + 0x560, D_002022E4 + 0x550, *(f32 *)(D_002022E4 + 0x570));
        func_0015B360(D_002F16C0, 1 << func_001C9B50());
        func_001B7290();
        func_0015C0C0(D_002F16C0);
        t = func_001787A0();
        func_0013BBC0(dt);
        D_0022273C[0] = func_001787A0() - t;
        func_001BC0E0();
        switch (D_00222A11[0]) {
        case 0:
            a = D_001F1BF0;
            b = D_001F1C00;
            sceVu0RotMatrixX(&m, &D_001F2170, WRAP(D_00201C2C));
            sceVu0RotMatrixY(&m, &m, WRAP(D_00201EB4));
            sceVu0CameraMatrix(&v, D_001F1BB0, &a.v, &b.v);
            sceVu0MulMatrix(&v, &v, &m);
            break;
        case 1:
            if (func_001C9BF0()) {
                func_001C8F90(&v);
            }
            break;
        }
        sceVu0MulMatrix(D_00222810, D_002F1900, &v);
        sceVu0MulMatrix(D_002227D0, D_002F1700, &v);
        t = func_001787A0();
        func_001ADA30(dt);
        D_00222740[0] = func_001787A0() - t;
        func_0015D300();
        t = func_001787A0();
        func_00169400(dt);
        D_00222744[0] = func_001787A0() - t;
        func_00159970(dt);
        func_00175B10(dt);
        func_00159310(0);
        func_001601C0(0);
        func_0015FEB0(func_001A9490(), dt);
        D_00222A10[0] = func_001A94A0();
    } else {
        t = func_001787A0();
        if (IS_func_0012A520(C)) func_001B4AF0(*C);
        if (IS_func_0012A520(D)) func_001B4AF0(*D);
        D_00222738[0] = func_001787A0() - t;
        func_0013BB70();
        t = func_001787A0();
        func_001AD390();
        D_00222740[0] = func_001787A0() - t;
        t = func_001787A0();
        func_00169630();
        D_00222744[0] = func_001787A0() - t;
        func_00159310(1);
        func_001601C0(1);
    }
    if (!D_00222A52[0].f.b3) func_00188F80();
}
#undef func_0012C7C0
#undef sceVu0CameraMatrix
#undef sceVu0MulMatrix
#undef D_00201E80
#undef D_002022E4
#undef D_00222A10
#undef D_001F2170
#undef D_002F1900
#undef D_002F1700
#undef D_002F16C0
#undef C
#undef D

/* func_0012AA30 */
#define func_00128210 func_00128210__as_func_0012AA30
int func_00128210__as_func_0012AA30();
#define func_00128460 func_00128460__as_func_0012AA30
int func_00128460__as_func_0012AA30();
#define func_0012AB40 func_0012AB40__as_func_0012AA30
int func_0012AB40__as_func_0012AA30();
#define func_001552A0 func_001552A0__as_func_0012AA30
int func_001552A0__as_func_0012AA30();
#define func_00155370 func_00155370__as_func_0012AA30
int func_00155370__as_func_0012AA30();
#define func_00160300 func_00160300__as_func_0012AA30
int func_00160300__as_func_0012AA30();
#define func_00169780 func_00169780__as_func_0012AA30
int func_00169780__as_func_0012AA30();
#define func_00169790 func_00169790__as_func_0012AA30
int func_00169790__as_func_0012AA30();
#define func_0016AB50 func_0016AB50__as_func_0012AA30
int func_0016AB50__as_func_0012AA30();
#define func_001AB280 func_001AB280__as_func_0012AA30
int func_001AB280__as_func_0012AA30();

void func_0012AA30(void) {
    func_00160300();
    func_0012AB40(4);
    func_0014DAB0(0);
    func_00155370();
    func_00128210(D_00222AF0);
    func_00128210(D_00222B20);
    func_00169780();
    func_001552A0();
    func_001B5940();
    func_001AF840();
    func_001C9C30();
    func_0016AB50();
    func_00189270();
    func_00128460(D_00222AF0, -1);
    func_00128460(D_00222B20, -1);
    func_00169790();
    func_00128210(D_00222AF0);
    func_00128210(D_00222B20);
    func_00169780();
    func_0012C380();
    switch (D_00201EA8) {
    case 0:
        func_001AB280();
        break;
    case 2:
        func_001AA760();
        break;
    }
}
#undef func_00128210
#undef func_00128460
#undef func_0012AB40
#undef func_001552A0
#undef func_00155370
#undef func_00160300
#undef func_00169780
#undef func_00169790
#undef func_0016AB50
#undef func_001AB280

/* func_0012AB40 */
#define func_00128210 func_00128210__as_func_0012AB40
void func_00128210__as_func_0012AB40(M2C_UNK *);
#define D_00222AF0 D_00222AF0__as_func_0012AB40
extern M2C_UNK D_00222AF0__as_func_0012AB40[];
#define D_00222B20 D_00222B20__as_func_0012AB40
extern M2C_UNK D_00222B20__as_func_0012AB40[];

void func_0012AB40(s32 arg0) {
    s32 i;

    for (i = 0; i < arg0; i++) {
        func_00155370();
        func_00128210(D_00222AF0);
        func_00128210(D_00222B20);
        func_00169780();
        func_001552A0();
        func_00128460(D_00222AF0, -1);
        func_00128460(D_00222B20, -1);
        func_00169790();
        func_00154B70();
        func_00153B50(0x80000000);
        func_00154AF0();
    }
}
#undef func_00128210
#undef D_00222AF0
#undef D_00222B20

/* func_0012AC00 */
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)
#define func_00128460 func_00128460__as_func_0012AC00
void func_00128460__as_func_0012AC00(void *, s32);
#define sceVu0CameraMatrix sceVu0CameraMatrix__as_func_0012AC00
void sceVu0CameraMatrix__as_func_0012AC00(Mtx *, void *, Vec *, Vec *);
#define sceVu0MulMatrix sceVu0MulMatrix__as_func_0012AC00
void sceVu0MulMatrix__as_func_0012AC00(void *, void *, Mtx *);
#define IDX ((&D_00201E80)[1])
#define ARR ((s32 **)(&D_00201E80 + 2))
#define D_001F2170 D_001F2170__as_func_0012AC00
extern Mtx D_001F2170__as_func_0012AC00;
#define D_002F1900 D_002F1900__as_func_0012AC00
extern s8 D_002F1900__as_func_0012AC00[];
#define D_002F1700 D_002F1700__as_func_0012AC00
extern s8 D_002F1700__as_func_0012AC00[];

void func_0012AC00(s32 arg0) {
    Info info;
    Mtx v;
    VQ a;
    VQ b;
    Mtx m;
    s32 st;
    u64 f;
    s32 i;
    s32 **p;

    func_00189580();
    func_0018A350(0x27);
    st = 1;
    do {
        func_00155370();
        func_00128210(D_00222AF0);
        func_00128210(D_00222B20);
        func_00178760();
        func_001769C0();
        func_0015FC10();
        func_0012D650();
        func_001296C0();
        func_001552A0();
        switch (st) {
        case 0:
            break;
        case 1:
            func_001A7D90(0);
            st++;
            break;
        case 2:
            if (D_002022E4 != NULL && ((f = D_002022E4->pad520[0x80]) & 1) && !((f & 1) && ((f << 61) >> 63))) {
                func_001C9E30();
                if (D_00201EA4 == 1) {
                    func_001A8E30();
                }
                st++;
            }
            break;
        case 3:
            IDX = 0;
            func_001B06E0(arg0, D_003139A0, 0);
            st++;
            break;
        case 4:
            func_001B0660(&info);
            if (info.x10 == arg0 && info.x14 == 3) {
                func_001B0450();
                i = IDX;
                ARR[i] = info.x18;
                func_001B7380(*ARR[i], i);
                func_001B7190(*ARR[IDX], IDX);
                if (D_00201EA4 == 1) {
                    if (func_001AA740() == 1) {
                        func_001C96F0(*ARR[IDX]);
                        func_001AA700(2);
                    }
                } else {
                    func_001C96F0(*ARR[IDX]);
                }
                st++;
            }
            break;
        case 5:
            func_001E1CC0();
            func_001E1D30(arg0, 0);
            st++;
            break;
        case 6:
            if (func_001E1D20()) {
                st++;
            }
            break;
        case 7:
            if (func_0012C7C0()) {
                IDX = !(IDX != 0);
                func_0012C1A0(*ARR[!(IDX != 0)]);
                func_0012F9D0(*info.x18);
                func_0012F6E0(1);
                if (D_00201EA4 == 1) {
                    func_0012C430();
                }
                st = 0;
            }
            break;
        }
        switch (D_00222A11[0]) {
        case 0:
            a = D_001F1BF0;
            b = D_001F1C00;
            sceVu0RotMatrixX(&m, &D_001F2170, WRAP(D_00201C2C));
            sceVu0RotMatrixY(&m, &m, WRAP(D_00201EB4));
            sceVu0CameraMatrix(&v, D_001F1BB0, &a.v, &b.v);
            sceVu0MulMatrix(&v, &v, &m);
            break;
        case 1:
            if (func_001C9BF0()) {
                func_001C8F90(&v);
            }
            break;
        }
        sceVu0MulMatrix(D_00222810, D_002F1900, &v);
        sceVu0MulMatrix(D_002227D0, D_002F1700, &v);
        func_00188F80();
        func_00128460(D_00222AF0, -1);
        func_00128460(D_00222B20, -1);
        func_0012B600();
        D_00201E94++;
    } while (st != 0);
    func_0018A350(0x12);
    func_0019A840();
}
#undef func_00128460
#undef sceVu0CameraMatrix
#undef sceVu0MulMatrix
#undef D_001F2170
#undef D_002F1900
#undef D_002F1700
#undef IDX
#undef ARR

/* func_0012B120 */
#define func_00129EE0 func_00129EE0__as_func_0012B120
void func_00129EE0__as_func_0012B120(void *);
#define func_00128A60 func_00128A60__as_func_0012B120
void func_00128A60__as_func_0012B120(void *, s32, s32, s32);
#define func_00128460 func_00128460__as_func_0012B120
void func_00128460__as_func_0012B120(void *, s32);
/* .bss, from the top down (CodeWarrior writes it in reverse) */

void func_0012B120(s32 arg0) {
    s32 v;
    func_00175C80();
    func_001643B0();
    func_0015DD90();
    func_0015BCA0();
    func_0015C8D0();
    func_00159A60();
    func_00159400(3.0f, D_003139A0);
    D_00222A30[0] = func_00159650(1);
    D_00222A34[0] = func_00159620(0);
    D_00222A38[0] = func_001595C0(1);
    D_00222A3C[0] = func_00159590(0);
    func_001595F0(1);
    func_00129EE0(D_00222790);
    func_00181240();
    func_00160300();
    D_00201C5C = 0x80000000;
    func_00128A60(D_00222AF0, D_00222B5C[0], D_00222B7C[0], 0x400);
    func_00174620(D_00222A80, D_00222AF0);
    if (D_00201EAC == 0) {
        func_0016AD10(D_00222B60[0], D_00222B80[0], 0x52BC6CE4);
        D_00201EAC = 1;
    }
    func_0016AB50();
    func_00128460(D_00222AF0, -1);
    func_00128460(D_00222B20, -1);
    func_00169790();
    func_001B7470(D_00222AF0, D_00201C10);
    func_001A82B0(D_00222AF0, D_00201C10);
    func_001AF970(D_00222AF0, D_00201C10);
    if (D_00201EA4 == 0) {
        func_001AB290(D_00201C34);
    } else {
        arg0 = func_001AA750();
    }
    func_0012AC00(arg0);
    v = func_001A9470() * 2;
    if (v > 0x7F) v = 0x7F;
    func_0012C6C0(v);
    v = func_001A9480() * 2;
    if (v > 0x7F) v = 0x7F;
    func_0012C730(v);
    func_0012DA60(func_001A9460());
}
#undef func_00129EE0
#undef func_00128A60
#undef func_00128460

/* func_0012B350 */
#define D_00201E80 D_00201E80__as_func_0012B350
extern Inner **D_00201E80__as_func_0012B350[2];
#define C (D_00201E80[2])
#define D (D_00201E80[3])
static inline s32 IS_func_0012B350(Inner **p) { if (p != NULL) return ((*p)->f & 1) != 0; else return 0; }
#define D_00201E94 D_00201E94__as_func_0012B350
extern u32 D_00201E94__as_func_0012B350;
#define func_0012B120 func_0012B120__as_func_0012B350
void func_0012B120__as_func_0012B350(void);
#define func_00128460 func_00128460__as_func_0012B350
void func_00128460__as_func_0012B350(void *, s32);

s32 func_0012B350(void) {
    s32 t;

    t = 0;
    func_0012B120();
    while (!D_00201E98 != 0) {
        D_00222A2C[0] = func_00154AC0();
        func_001E8500();
        D_00222734[0] = func_001787A0() - t;
        D_00222A54[0].b = 0;
        func_00155370();
        func_00128210(D_00222AF0);
        func_00128210(D_00222B20);
        func_00169780();
        D_00222730[0] = func_001787A0() - t;
        func_00178760();
        t = func_001787A0();
        func_001769C0();
        func_0015FC10();
        func_001296C0();
        func_001552A0();
        func_0012A520(0.033333335f);
        func_001C9830();
        if (IS_func_0012B350(C)) func_001B4100(*C);
        if (IS_func_0012B350(D)) func_001B4100(*D);
        func_00128460(D_00222AF0, -1);
        func_00128460(D_00222B20, -1);
        func_00169790();
        func_0012A070();
        if (D_00201E94 % 15 == 0 && sceCdSync(1) == 0) {
            func_001DF9A0();
        }
        D_00201E94++;
    }
    func_0012AA30();
    return 0;
}
#undef func_0012B120
#undef func_00128460
#undef D_00201E80
#undef D_00201E94
#undef C
#undef D

/* func_0012B550 */
#define func_00128210 func_00128210__as_func_0012B550
int func_00128210__as_func_0012B550();
#define func_00128460 func_00128460__as_func_0012B550
int func_00128460__as_func_0012B550();
#define func_00153B50 func_00153B50__as_func_0012B550
int func_00153B50__as_func_0012B550();
#define func_00154B70 func_00154B70__as_func_0012B550
int func_00154B70__as_func_0012B550();
#define func_001552A0 func_001552A0__as_func_0012B550
int func_001552A0__as_func_0012B550();
#define func_00155370 func_00155370__as_func_0012B550
int func_00155370__as_func_0012B550();
#define D_00222AF0 D_00222AF0__as_func_0012B550
extern s32 D_00222AF0__as_func_0012B550[];
#define D_00222B20 D_00222B20__as_func_0012B550
extern s32 D_00222B20__as_func_0012B550[];

void func_0012B550(void) {
    s32 var_16;

    func_00155370();
    func_00128210(D_00222AF0);
    func_00128210(D_00222B20);
    func_001552A0();
    var_16 = 0;
    do {
        func_00154B70();
        func_00153B50(0x80000000);
        func_00154AF0();
        func_00155370();
        func_001552A0();
        var_16 += 1;
    } while (var_16 < 4);
    func_00189080();
    func_00128460(D_00222B20, -1U);
    func_00128210(D_00222B20);
}
#undef D_00222AF0
#undef D_00222B20
#undef func_00128210
#undef func_00128460
#undef func_00153B50
#undef func_00154B70
#undef func_001552A0
#undef func_00155370

/* func_0012B600 */
#define D_002F1800 D_002F1800__as_func_0012B600
extern u8 D_002F1800__as_func_0012B600[];
#define D_002F1840 D_002F1840__as_func_0012B600
extern u8 D_002F1840__as_func_0012B600[];

void func_0012B600(void) {
    Buf b;
    s32 z;
    f32 d;
    func_00154B70();
    func_00176A60();
    func_001547F0(0, 0);
    func_00154B00(D_002F1800);
    func_001545D0();
    func_001543E0(0x49, 0);
    func_001543E0(0x4C, 0x5015E);
    func_001543E0(0x40, 0x13F0000 | (s64)0xDF0000 << 32);
    func_001543E0(0x3B, 0x80 | (s64)0x80 << 32);
    func_001543E0(0x18, 0x7600 | (s64)0x7900 << 32);
    func_001543E0(0x4E, 0x3A000118);
    func_001543E0(0x47, 0x51000);
    func_00154420();
    func_0015B270();
    func_001549D0();
    func_00155900();
    func_001547F0(3, 0);
    func_00154B00(D_002F1840);
    func_00153740();
    memset(&b, 0, 0x50);
    z = 0;
    b.f4C.b0 = z;
    b.f4C.b1 = z;
    b.f4C.b2 = z;
    func_001545D0();
    func_001543E0(0x47, 0x30000);
    func_001544C0();
    b.x0 = 0x6C00;
    b.x8 = 0;
    b.x18 = 0;
    d = 224.0f - D_00201E90;
    b.x4 = (s32)(2048.0f - d) << 4;
    b.x10 = 0x9400;
    b.x44 = 0x80000000;
    b.x14 = (s32)(2048.0f + d) << 4;
    func_00155BD0(&b);
    func_00155900();
    func_00154700(5, -2);
    func_001545D0();
    func_001543E0(0x40, 0x27F0000 | (s64)0x1BF0000 << 32);
    func_001543E0(0x41, 0x27F0000 | (s64)0x1BF0000 << 32);
    func_001543E0(0x49, 0);
    func_001544C0();
    func_00188F70();
    func_00187B20(0);
    func_00155900();
    func_00154700(5, 0);
    func_001545D0();
    func_001543E0(0x40, 0x27F0000 | (s64)0x1BF0000 << 32);
    func_001543E0(0x41, 0x27F0000 | (s64)0x1BF0000 << 32);
    func_001543E0(0x42, 0x88);
    func_001544C0();
    func_00180F80();
    func_00155900();
    func_00154AF0();
    func_00176A40();
}
#undef D_002F1800
#undef D_002F1840

/* func_0012B8E0 */
#define WRAP(x) ((((3.1415927f + (x)) - 6.2831855f * (s32)(0.15915494f * (3.1415927f + (x)))) + ((3.1415927f + (x)) < 0.0f ? 6.2831855f : 0.0f)) - 3.1415927f)
#define func_00128A60 func_00128A60__as_func_0012B8E0
void func_00128A60__as_func_0012B8E0(void *, s32, s32, s32);
#define func_00128460 func_00128460__as_func_0012B8E0
void func_00128460__as_func_0012B8E0(void *, s32);
#define sceVu0CameraMatrix sceVu0CameraMatrix__as_func_0012B8E0
void sceVu0CameraMatrix__as_func_0012B8E0(Mtx *, void *, Vec *, Vec *);
#define sceVu0MulMatrix sceVu0MulMatrix__as_func_0012B8E0
void sceVu0MulMatrix__as_func_0012B8E0(void *, void *, Mtx *);
#define D_00222A10 D_00222A10__as_func_0012B8E0
extern u8 D_00222A10__as_func_0012B8E0[];
#define D_001F2170 D_001F2170__as_func_0012B8E0
extern Mtx D_001F2170__as_func_0012B8E0;
#define D_002F1900 D_002F1900__as_func_0012B8E0
extern s8 D_002F1900__as_func_0012B8E0[];
#define D_002F1700 D_002F1700__as_func_0012B8E0
extern s8 D_002F1700__as_func_0012B8E0[];

s32 func_0012B8E0(s32 arg0) {
    Mtx v;
    VQ a;
    VQ b;
    Mtx m;
    s32 t;

    func_00181240();
    func_00128A60(D_00222AF0, D_00222B5C[0], D_00222B7C[0], 0x200);
    func_00128460(D_00222AF0, -1);
    func_00128460(D_00222B20, -1);
    func_001891C0();
    func_0018A350(arg0);
    t = func_001A9470() * 2;
    t = (t > 0x7F) ? 0x7F : t;
    func_0012C6C0(t);
    t = func_001A9480() * 2;
    t = (t > 0x7F) ? 0x7F : t;
    func_0012C730(t);
    func_0012DA60(func_001A9460());
    while (!D_00201E98 != 0) {
        func_001E8500();
        D_00222A54[0].b = 0;
        func_00155370();
        func_00128210(D_00222AF0);
        func_00128210(D_00222B20);
        func_00178760();
        func_001769C0();
        func_0015FC10();
        func_0012D650();
        func_001296C0();
        func_001552A0();
        switch (D_00222A11[0]) {
        case 0:
            a = D_001F1BF0;
            b = D_001F1C00;
            sceVu0RotMatrixX(&m, &D_001F2170, WRAP(D_00201C2C));
            sceVu0RotMatrixY(&m, &m, WRAP(D_00201EB4));
            sceVu0CameraMatrix(&v, D_001F1BB0, &a.v, &b.v);
            sceVu0MulMatrix(&v, &v, &m);
            break;
        case 1:
            if (func_001C9BF0()) {
                func_001C8F90(&v);
            }
            break;
        }
        sceVu0MulMatrix(D_00222810, D_002F1900, &v);
        sceVu0MulMatrix(D_002227D0, D_002F1700, &v);
        func_00188F80();
        func_00128460(D_00222AF0, -1);
        func_00128460(D_00222B20, -1);
        D_00222A10[0] = func_001A94A0();
        func_0012B600();
        D_00201E94++;
    }
    func_0012B550();
    return 0;
}
#undef func_00128A60
#undef func_00128460
#undef sceVu0CameraMatrix
#undef sceVu0MulMatrix
#undef D_00222A10
#undef D_001F2170
#undef D_002F1900
#undef D_002F1700

/* func_0012BC80 */
#define D_00222A10 D_00222A10__as_func_0012BC80
extern G D_00222A10__as_func_0012BC80;
#define D_00222700 D_00222700__as_func_0012BC80
extern u8 D_00222700__as_func_0012BC80[];
#define func_00129400 func_00129400__as_func_0012BC80
void func_00129400__as_func_0012BC80(void *, s32, s32);

void func_0012BC80(void) {
    func_00129400(D_001FAB40, 0x100, 0);
    func_00129040();
    func_00129030();
    func_0015FC60();
    func_00160350();
    func_001787F0();
    func_00178DB0();
    func_00128F10();
    func_00128D10();
    memset(&D_00222A10, 0, 0x48);
    D_00222A10.x0 = 0;
    D_00222A10.x30 = 75.0f;
    D_00222A10.x1 = 1;
    D_00222A10.x2 = 1;
    D_00222A10.x4 = -1;
    D_00222A10.x38 = 0.3f;
    D_00222A10.x6 = -1;
    D_00222A10.x8 = -1;
    D_00222A10.xA = -1;
    D_00222A10.f40.f.b6 = 0;
    D_00222A10.f41.f.b7 = 0;
    D_00222A10.f41.f.b2 = 0;
    D_00222A10.f42.f.b3 = 0;
    D_00222A10.f40.f.b3 = 0;
    D_00222A10.f42.f.b1 = 0;
    D_00222A10.f43.f.b2 = 1;
    D_00222A10.f43.f.b3 = 1;
    D_00222A10.f43.f.b4 = 1;
    D_00222A10.f44.f.b0 = 0;
    D_00222A10.f44.f.b1 = 0;
    D_00222A10.f44.f.b2 = 0;
    D_00222A10.f44.f.b6 = 1;
    func_00155460(D_00222B58[0], D_00222B78[0]);
    func_0014DB60();
    func_001B07B0();
    func_001A5340();
    func_001AF980();
    func_001E1770();
    func_001E1D70();
    func_001781A0(0x3040, 0xFC0);
    func_00188830(D_00222700);
}
#undef func_00129400
#undef D_00222A10
#undef D_00222700

/* func_0012BF40 */
#define func_00128210 func_00128210__as_func_0012BF40
int func_00128210__as_func_0012BF40();
#define func_00128460 func_00128460__as_func_0012BF40
int func_00128460__as_func_0012BF40();
#define func_00128A60 func_00128A60__as_func_0012BF40
int func_00128A60__as_func_0012BF40();
#define func_0012B350 func_0012B350__as_func_0012BF40
int func_0012B350__as_func_0012BF40();
#define func_0012B8E0 func_0012B8E0__as_func_0012BF40
int func_0012B8E0__as_func_0012BF40();
#define func_0012BC80 func_0012BC80__as_func_0012BF40
int func_0012BC80__as_func_0012BF40();
#define D_00222AF0 D_00222AF0__as_func_0012BF40
extern s32 D_00222AF0__as_func_0012BF40[];
#define D_00222B20 D_00222B20__as_func_0012BF40
extern s32 D_00222B20__as_func_0012BF40[];
#define D_00222B5C D_00222B5C__as_func_0012BF40
extern void *D_00222B5C__as_func_0012BF40[];

void func_0012BF40(void) {
    D_00201E94 = 0;
    func_0012BC80();
    func_001AB280();
    func_00128A60(D_00222B20, (*D_00222B68), (*D_00222B88), 0x100);
    func_00128460(D_00222B20, -1U);
    func_00189AD0((s32) D_00222B20);
    func_00128210(D_00222B20);
    func_00128A60(D_00222AF0, (*D_00222B5C), (*D_00222B7C), 0x200);
    func_00128460(D_00222AF0, -1U);
    func_0012DEE0((s32) D_00222AF0);
    func_00128210(D_00222AF0);
loop_1:
    if (D_00201E9C == 0) {
        func_0012B8E0(D_00201C28);
    }
    D_00201E98 = 0;
    D_00201E9C = 0;
    func_0012B350(D_00201C30);
    D_00201E98 = 0;
    goto loop_1;
}
#undef D_00222AF0
#undef D_00222B20
#undef D_00222B5C
#undef func_00128210
#undef func_00128460
#undef func_00128A60
#undef func_0012B350
#undef func_0012B8E0
#undef func_0012BC80

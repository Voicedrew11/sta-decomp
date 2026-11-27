#include "common.h"
void func_001AB690(void);
void* func_001ABB20(void);

/* func_001AB690 */
typedef struct { u8 pad[0x14]; s32 x14; Flags8 f18; } A;
typedef struct { u8 pad[0x90]; s32 x90; u8 pad2[0x8]; s16 h9C; s16 h9E; u8 pad3[8]; Flags8 fA8; } B;
typedef struct { u8 a:3; u8 f:3; u8 c:2; } F3b;
extern A *D_00202290;
extern s32 D_0020228C;
extern B *D_00202288;
extern s32 D_002022A0;
extern s32 D_004B4B70[];
extern s32 D_004B4B74[];
extern s32 D_004B4B78[];
extern s32 D_004B4B7C[];
extern s32 *D_004B4B80[];
extern s32 *D_004B4B84[];
extern s32 D_004B4B88[];
extern F3b D_00222A54[];
extern s8 D_001FD9D0[];
extern s8 D_001FD9F0[];
extern s8 D_00270F40[];
void func_00128580(A *, s32 *);
void func_0014DAB0(s32);
void* func_001ABB20(void);
void sprintf(s8 *, s8 *, s32);
void strcpy(s8 *, s8 *);
s32 func_00159D10(s8 *);
s32 func_0015ABD0(s32);
s32 func_0015A300(s32);
void func_0015AB80(s32);
s32 *func_001288C0(A *, s32);
s32 func_0014DB00(s8 *, s32, s8 *);
s32 func_0014DA70(s32);
void func_0014DAC0(s32, s32);
u8 func_0014DAF0(s32);
void FlushCache(s32);
void func_001789E0(s32, s8 *, s32);
void memcpy(s32, s8 *, s32);
void func_0014DAE0(s32);
s32 func_0014DA90(s32, s32, s32, s32);
s32 func_0014DA80(s32, s32);
s32 *func_0016F950(s32, s32 *);
s32 func_0016FF80(s32);
void func_001ABCC0(B *, s32 *);
static inline void cleanup(void) {
    if (D_004B4B80[0]) func_00128580(D_00202290, D_004B4B80[0]);
    if (D_004B4B74[0]) {
        func_0014DAB0(D_004B4B74[0]);
        D_004B4B74[0] = 0;
    }
    D_004B4B80[0] = 0;
    D_00202288 = 0;
    D_004B4B74[0] = 0;
    D_0020228C = 0;
    D_004B4B70[0] = 0;
    D_004B4B88[0] = 0;
}

void func_001AB690(void) {
    s8 buf2[0x100];
    s8 buf1[0x100];
    s32 s;
    u32 n;
    s32 r;
    s32 q;
    s32 p;
    B *b;
    s32 c;
    s32 k;

    if (D_00202290 == NULL) return;
    if (D_00202290->f18.f.b1 && D_00202290->x14 != 0) return;
    if (D_0020228C != 0) {
        cleanup();
        return;
    }
    if (D_00202288 == 0) D_00202288 = func_001ABB20();
    if (D_00202288 == 0) return;
    if (!D_00202288->fA8.f.b1) {
        c = D_00202288->h9E == 2 && D_00202288->h9C >= 800;
        k = D_00202288->h9C;
        if (c) sprintf(buf1, D_001FD9D0, k);
        else sprintf(buf1, D_001FD9F0, k);
        strcpy(buf2, buf1);
        if (D_004B4B78) {
            s = func_0015ABD0(func_00159D10(buf1));
            D_004B4B78[0] = func_0015A300(s);
            func_0015AB80(s);
        }
        D_004B4B80[0] = func_001288C0(D_00202290, D_004B4B78[0]);
        D_004B4B84[0] = 0;
        D_004B4B7C[0] = 0;
        D_004B4B74[0] = func_0014DB00(buf2, 0x102, D_00270F40);
        D_004B4B7C[0] = func_0014DA70(D_004B4B74[0]);
        func_0014DAC0(D_004B4B74[0], 0);
        D_00202288->fA8.f.b1 = 1;
    }
    switch (func_0014DAF0(D_004B4B74[0])) {
    case 0:
        break;
    case 5:
        n = D_004B4B78[0] - D_004B4B7C[0];
        n = (n > 0x80000) ? 0x80000 : n;
        q = (s32)n >> 4;
        r = n - q * 16;
        FlushCache(0);
        func_001789E0(*D_004B4B80[0] + D_004B4B7C[0], D_00270F40, q);
        if (r > 0) memcpy(*D_004B4B80[0] + D_004B4B7C[0] + q * 16, D_00270F40 + q * 16, r);
        D_004B4B7C[0] += n;
        func_0014DAE0(D_004B4B74[0]);
        break;
    case 3:
    case 6:
        if (D_004B4B70[0] != 0) break;
        p = *D_004B4B80[0];
        if (D_004B4B88[0] == 0) {
            if (func_0014DA90(D_004B4B74[0], p, p, D_004B4B78[0])) D_004B4B88[0] = 1;
        }
        if (D_004B4B88[0] != 0 && func_0014DA80(D_004B4B74[0], 8) != 0) break;
        D_004B4B88[0] = 0;
        D_004B4B84[0] = func_0016F950(D_002022A0, D_004B4B80[0]);
        b = D_00202288;
        b->x90 = func_0016FF80(*D_004B4B84[0]);
        func_001ABCC0(D_00202288, D_004B4B84[0]);
        D_004B4B80[0] = 0;
        D_004B4B70[0] = 1;
        cleanup();
        break;
    case 1:
    case 2:
    case 4:
        D_00222A54[0].f = 3;
        break;
    }
}

/* func_001ABB20 */
extern s32 D_004AC630[];
extern s32 D_004AC970[];
extern s32 D_004AD670[];
extern s32 D_004AE370[];
extern s32 D_004B1770[];

void *func_001ABB20(void) {
    u8 temp_4_5;
    u8 temp_4_4;
    u8 temp_4_3;
    u8 temp_4_2;
    u8 temp_4;
    s32 var_6_5;
    s32 var_6_4;
    s32 var_6_3;
    s32 var_6_2;
    s32 var_6;
    s32 *var_2_5;
    s32 *var_2_4;
    s32 *var_2_3;
    s32 *var_2_2;
    s32 *var_2;

    var_6 = 0;
    var_2_5 = (s32 *) (D_004AC630);
loop_1:
    if (M2C_FIELD(var_2_5, s16 *, 0x9C) != -1) {
        temp_4 = M2C_FIELD(var_2_5, u8 *, 0xA8);
        if (!(temp_4 & 1) && (((u64) ((s64) temp_4 << 0x3E) >> 0x3F) == 0)) {
            return (s32 *) (var_2_5);
        }
    }
    var_6 += 1;
    var_2_5 = (s32*)((u8 *)var_2_5 + 0xD0);
    if (var_6 >= 4) {
        var_6_2 = 0;
        var_2_4 = (s32 *) (D_004AC970);
loop_7:
        if (M2C_FIELD(var_2_4, s16 *, 0x9C) != -1) {
            temp_4_2 = M2C_FIELD(var_2_4, u8 *, 0xA8);
            if (!(temp_4_2 & 1) && (((u64) ((s64) temp_4_2 << 0x3E) >> 0x3F) == 0)) {
                return (s32 *) (var_2_4);
            }
        }
        var_6_2 += 1;
        var_2_4 = (s32*)((u8 *)var_2_4 + 0xD0);
        if (var_6_2 >= 0x10) {
            var_6_3 = 0;
            var_2_3 = (s32 *) (D_004AD670);
loop_13:
            if (M2C_FIELD(var_2_3, s16 *, 0x9C) != -1) {
                temp_4_3 = M2C_FIELD(var_2_3, u8 *, 0xA8);
                if (!(temp_4_3 & 1) && (((u64) ((s64) temp_4_3 << 0x3E) >> 0x3F) == 0)) {
                    return (s32 *) (var_2_3);
                }
            }
            var_6_3 += 1;
            var_2_3 = (s32*)((u8 *)var_2_3 + 0xD0);
            if (var_6_3 >= 0x10) {
                var_6_4 = 0;
                var_2_2 = (s32 *) (D_004AE370);
loop_19:
                if (M2C_FIELD(var_2_2, s16 *, 0x9C) != -1) {
                    temp_4_4 = M2C_FIELD(var_2_2, u8 *, 0xA8);
                    if (!(temp_4_4 & 1) && (((u64) ((s64) temp_4_4 << 0x3E) >> 0x3F) == 0)) {
                        return (s32 *) (var_2_2);
                    }
                }
                var_6_4 += 1;
                var_2_2 = (s32*)((u8 *)var_2_2 + 0xD0);
                if (var_6_4 >= 0x40) {
                    var_6_5 = 0;
                    var_2 = (s32 *) (D_004B1770);
loop_25:
                    if (M2C_FIELD(var_2, s16 *, 0x9C) != -1) {
                        temp_4_5 = M2C_FIELD(var_2, u8 *, 0xA8);
                        if (!(temp_4_5 & 1) && (((u64) ((s64) temp_4_5 << 0x3E) >> 0x3F) == 0)) {
                            return (s32 *) (var_2);
                        }
                    }
                    var_6_5 += 1;
                    var_2 = (s32*)((u8 *)var_2 + 0xD0);
                    if (var_6_5 >= 0x40) {
                        return NULL;
                    }
                    goto loop_25;
                }
                goto loop_19;
            }
            goto loop_13;
        }
        goto loop_7;
    }
    goto loop_1;
}

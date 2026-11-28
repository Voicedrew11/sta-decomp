#include "common.h"
typedef struct { u8 pad[0x40]; u32 x40[8]; u8 pad2[0x160]; } G;
typedef struct { s8 pad[0x40]; u32 bits[(0x1C0 - 0x40) / 4]; } Rec_MapState_SetBit_0_001A9CA0;
typedef struct { s8 pad[0x180]; u32 bits[16]; } Rec_MapState_GetField_0_001A9D50;
typedef struct { u8 pad[0x180]; s32 w[16]; } Rec_MapState_SetField_0_001A9E10;
extern G *D_00201DC4;
extern s16 D_001F37B0[];
s32 MapState_TestBit_0_001A9BE0(s32 k, s16 b);
void MapState_SetBit_0_001A9CA0(s32 id, s16 k);
u32 MapState_GetField_0_001A9D50(s32 id, u16 k);
void MapState_SetField_0_001A9E10(s32 id, u16 k, u8 v);

/* MapState_TestBit_0_001A9BE0 */
static inline s32 find_MapState_TestBit_0_001A9BE0(s32 k) {
    u32 i;
    for (i = 0; i < 0x2A; i++) {
        if (k == D_001F37B0[i]) return i;
    }
    return -1;
}

s32 MapState_TestBit_0_001A9BE0(s32 k, s16 b) {
    s32 i = find_MapState_TestBit_0_001A9BE0(k);
    if (i == -1) return 0;
    return (D_00201DC4[i].x40[b / 32] & (1 << (b % 32))) != 0;
}

/* MapState_SetBit_0_001A9CA0 */
#define D_00201DC4 D_00201DC4__as_MapState_SetBit_0_001A9CA0
extern Rec_MapState_SetBit_0_001A9CA0 *D_00201DC4__as_MapState_SetBit_0_001A9CA0;
static inline u32 find_MapState_SetBit_0_001A9CA0(s32 id) {
    u32 i;
    for (i = 0; i < 42; i++) {
        if (id == D_001F37B0[i]) {
            return i;
        }
    }
    return -1;
}
void MapState_SetBit_0_001A9CA0(s32 id, s16 k) {
    u32 idx = find_MapState_SetBit_0_001A9CA0(id);
    if (idx != -1) {
        D_00201DC4[idx].bits[k / 32] |= 1 << (k % 32);
    }
}
#undef D_00201DC4

/* MapState_GetField_0_001A9D50 */
#define D_00201DC4 D_00201DC4__as_MapState_GetField_0_001A9D50
extern Rec_MapState_GetField_0_001A9D50 *D_00201DC4__as_MapState_GetField_0_001A9D50;
static inline u32 find_MapState_GetField_0_001A9D50(s32 id) {
    u32 i;
    for (i = 0; i < 42; i++) {
        if (id == D_001F37B0[i]) {
            return i;
        }
    }
    return -1;
}
u32 MapState_GetField_0_001A9D50(s32 id, u16 k) {
    u32 i = find_MapState_GetField_0_001A9D50(id);
    s32 sh;
    s32 n;
    if (i == -1) {
        return 0;
    }
    n = k * 2;
    sh = n % 32;
    return ((3 << sh) & D_00201DC4[i].bits[n / 32]) >> sh;
}
#undef D_00201DC4

/* MapState_SetField_0_001A9E10 */
#define D_00201DC4 D_00201DC4__as_MapState_SetField_0_001A9E10
extern Rec_MapState_SetField_0_001A9E10 *D_00201DC4__as_MapState_SetField_0_001A9E10;
static inline u32 find_MapState_SetField_0_001A9E10(s32 id) {
    u32 i;
    for (i = 0; i < 42; i++) {
        if (id == D_001F37B0[i]) {
            return i;
        }
    }
    return -1;
}
void MapState_SetField_0_001A9E10(s32 id, u16 k, u8 v) {
    u32 i = find_MapState_SetField_0_001A9E10(id);
    if (i != -1) {
        s32 b = k * 2;
        D_00201DC4[i].w[b / 32] |= (v & 3) << (b % 32);
    }
}
#undef D_00201DC4

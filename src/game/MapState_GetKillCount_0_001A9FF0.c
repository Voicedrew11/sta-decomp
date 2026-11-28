#include "common.h"
#include "m2c.h"
typedef struct { u8 pad[0x499E]; u16 t[1]; } Rec_MapState_GetKillCount_0_001A9FF0;
typedef struct { u8 pad[0x497E]; u16 t[1]; } S;
typedef struct { u8 pad[0x4980]; u16 a[16]; u16 b[16]; } Big;
typedef struct { s32 v[8]; u32 n[0x68]; } E_MapState_GetCounter_0_001AA1E0;
typedef struct { s8 pad[0x20]; u32 bits[(0x1C0 - 0x20) / 4]; } Rec_MapState_IncCounter_0_001AA2A0;
typedef struct { u8 pad[0x50]; Flags8 x50; u8 pad2[0x16F]; } G;
typedef struct { s8 pad[0x50]; u8 b0 : 1; u8 r : 7; s8 rest[0x1C0 - 0x51]; } Rec_MapState_SetVisited_0_001AA4C0;
typedef struct { s32 v[0x70]; } E_MapState_GetWord_1_001AA540;
typedef struct { s32 v[0x70]; } Rec_MapState_SetWord_1_001AA5D0;
extern s16 D_001F37B0[];
extern Rec_MapState_GetKillCount_0_001A9FF0 *D_00201DC4;
u16 MapState_GetKillCount_0_001A9FF0(s32 id);
u16 MapState_GetBestKillRate_0_001AA090(s32 a);
void MapState_IncVisits_0_001AA130(s32 id);
s32 MapState_GetCounter_0_001AA1E0(s32 arg0, s16 arg1);
void MapState_IncCounter_0_001AA2A0(s32 id, s16 k);
s32 MapState_IsVisited_1_001AA440(s32 k);
void MapState_SetVisited_0_001AA4C0(s32 id);
s32 MapState_GetWord_1_001AA540(s32 arg0, s16 arg1);
void MapState_SetWord_1_001AA5D0(s32 id, s16 k, s32 v);

/* MapState_GetKillCount_0_001A9FF0 */
static inline u32 find_MapState_GetKillCount_0_001A9FF0(s32 id) {
    u32 i;
    for (i = 0; i < 42; i++) {
        if (id == D_001F37B0[i]) {
            return i;
        }
    }
    return -1;
}
u16 MapState_GetKillCount_0_001A9FF0(s32 id) {
    u32 i = find_MapState_GetKillCount_0_001A9FF0(id);
    if (i == -1) {
        return 0;
    }
    return D_00201DC4->t[id / 10];
}

/* MapState_GetBestKillRate_0_001AA090 */
#define D_00201DC4 D_00201DC4__as_MapState_GetBestKillRate_0_001AA090
extern S *D_00201DC4__as_MapState_GetBestKillRate_0_001AA090;
static inline s32 find_MapState_GetBestKillRate_0_001AA090(s32 k) { u32 i; for (i = 0; i < 0x2A; i++) if (k == D_001F37B0[i]) return i; return -1; }
u16 MapState_GetBestKillRate_0_001AA090(s32 a) {
 if (find_MapState_GetBestKillRate_0_001AA090(a) == -1) return 0; return D_00201DC4->t[a / 10];
}
#undef D_00201DC4

/* MapState_IncVisits_0_001AA130 */
#define D_00201DC4 D_00201DC4__as_MapState_IncVisits_0_001AA130
extern Big *D_00201DC4__as_MapState_IncVisits_0_001AA130;
static inline u32 find_MapState_IncVisits_0_001AA130(s32 id) {
    u32 i;
    for (i = 0; i < 42; i++) {
        if (id == D_001F37B0[i]) {
            return i;
        }
    }
    return -1;
}
void MapState_IncVisits_0_001AA130(s32 id) {
    u32 i = find_MapState_IncVisits_0_001AA130(id);
    if (i != -1) {
        s32 k = id / 10 - 1;
        D_00201DC4->a[k]++;
        if (D_00201DC4->b[k] < D_00201DC4->a[k]) D_00201DC4->b[k] = D_00201DC4->a[k];
    }
}
#undef D_00201DC4

/* MapState_GetCounter_0_001AA1E0 */
#define D_00201DC4 D_00201DC4__as_MapState_GetCounter_0_001AA1E0
extern E_MapState_GetCounter_0_001AA1E0 *D_00201DC4__as_MapState_GetCounter_0_001AA1E0;

static inline s32 find_MapState_GetCounter_0_001AA1E0(s32 a) {
    u32 i;
    for (i = 0; i < 0x2A; i++) {
        if (a == D_001F37B0[i]) return i;
    }
    return -1;
}

s32 MapState_GetCounter_0_001AA1E0(s32 arg0, s16 arg1) {
    s32 i = find_MapState_GetCounter_0_001AA1E0(arg0);
    if (i == -1) return 0;
    return (D_00201DC4[i].n[arg1 / 8] >> (arg1 % 8 * 4)) & 0xF;
}
#undef D_00201DC4

/* MapState_IncCounter_0_001AA2A0 */
#define D_00201DC4 D_00201DC4__as_MapState_IncCounter_0_001AA2A0
extern Rec_MapState_IncCounter_0_001AA2A0 *D_00201DC4__as_MapState_IncCounter_0_001AA2A0;
static inline u32 find_MapState_IncCounter_0_001AA2A0(s32 id) {
    u32 i;
    for (i = 0; i < 42; i++) {
        if (id == D_001F37B0[i]) {
            return i;
        }
    }
    return -1;
}
static inline u32 get(s32 id, s16 k) {
    u32 i = find_MapState_IncCounter_0_001AA2A0(id);
    if (i == -1) {
        return 0;
    }
    return (D_00201DC4[i].bits[k / 8] >> (k % 8 * 4)) & 0xF;
}

void MapState_IncCounter_0_001AA2A0(s32 id, s16 k) {
    u32 idx = find_MapState_IncCounter_0_001AA2A0(id);
    u32 v = get(id, k) + 1;
    if (idx != -1) {
        if (v > 16) {
            v = 16;
        }
        D_00201DC4[idx].bits[k / 8] &= ~(0xF << (k % 8 * 4));
        D_00201DC4[idx].bits[k / 8] |= v << (k % 8 * 4);
    }
}
#undef D_00201DC4

/* MapState_IsVisited_1_001AA440 */
#define D_00201DC4 D_00201DC4__as_MapState_IsVisited_1_001AA440
extern G *D_00201DC4__as_MapState_IsVisited_1_001AA440;
static inline s32 find_MapState_IsVisited_1_001AA440(s32 k) {
    u32 i;
    for (i = 0; i < 0x2A; i++) {
        if (k == D_001F37B0[i]) return i;
    }
    return -1;
}
s32 MapState_IsVisited_1_001AA440(s32 k) {
    s32 i = find_MapState_IsVisited_1_001AA440(k);
    if (i == -1) return 0;
    return D_00201DC4[i].x50.f.b0;
}
#undef D_00201DC4

/* MapState_SetVisited_0_001AA4C0 */
#define D_00201DC4 D_00201DC4__as_MapState_SetVisited_0_001AA4C0
extern Rec_MapState_SetVisited_0_001AA4C0 *D_00201DC4__as_MapState_SetVisited_0_001AA4C0;
static inline u32 find_MapState_SetVisited_0_001AA4C0(s32 id) {
    u32 i;
    for (i = 0; i < 42; i++) {
        if (id == D_001F37B0[i]) {
            return i;
        }
    }
    return -1;
}
void MapState_SetVisited_0_001AA4C0(s32 id) {
    u32 i = find_MapState_SetVisited_0_001AA4C0(id);
    if (i != -1) {
        D_00201DC4[i].b0 = 1;
    }
}
#undef D_00201DC4

/* MapState_GetWord_1_001AA540 */
#define D_00201DC4 D_00201DC4__as_MapState_GetWord_1_001AA540
extern E_MapState_GetWord_1_001AA540 *D_00201DC4__as_MapState_GetWord_1_001AA540;

static inline s32 find_MapState_GetWord_1_001AA540(s32 a) {
    u32 i;
    for (i = 0; i < 0x2A; i++) {
        if (a == D_001F37B0[i]) return i;
    }
    return -1;
}

s32 MapState_GetWord_1_001AA540(s32 arg0, s16 arg1) {
    s32 i = find_MapState_GetWord_1_001AA540(arg0);
    if (i == -1) return 0;
    return D_00201DC4[i].v[arg1];
}
#undef D_00201DC4

/* MapState_SetWord_1_001AA5D0 */
#define D_00201DC4 D_00201DC4__as_MapState_SetWord_1_001AA5D0
extern Rec_MapState_SetWord_1_001AA5D0 *D_00201DC4__as_MapState_SetWord_1_001AA5D0;
static inline u32 find_MapState_SetWord_1_001AA5D0(s32 id) {
    u32 i;
    for (i = 0; i < 42; i++) {
        if (id == D_001F37B0[i]) {
            return i;
        }
    }
    return -1;
}
void MapState_SetWord_1_001AA5D0(s32 id, s16 k, s32 v) {
    u32 i = find_MapState_SetWord_1_001AA5D0(id);
    if (i != -1) {
        D_00201DC4[i].v[k] = v;
    }
}
#undef D_00201DC4

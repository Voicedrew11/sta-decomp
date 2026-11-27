#include "m2c.h"
typedef struct { u8 a, b, c, d; } C4;
typedef struct {
    s16 x0;
    s16 x2;
    s16 x4;
    s16 x6;
    u8 pad8[0x38];
    u32 x40;
    u8 pad44[0x1C];
    s32 x60;
    u8 pad64[0xC];
    u16 x70[8];
    s16 x80[10];
    u8 x94_;
    u8 pad95[0xB];
    C4 col[1024];
} S;
typedef struct {
    u8 pad[0x39C];
    u8 x39C;
    u8 pad39D[0x418 - 0x39D];
    s16 x418;
    u16 x41A;
    u8 pad41C[0x44];
    u16 x460[8];
    u16 x470[8];
    u8 x480[0x20];
    u8 x4A0[0x20];
} Q;
typedef struct { u8 pad[4]; u16 x4; u8 pad6[0x1A]; u16 x20; u8 pad22[0x6E]; } E;
S *PlayerData_Get_2_001C9BA0(void);
Q *Player_GetBodyState_1_001C9B60(void);
E *Item_GetTable_1_001AFC90(void);
void memset(void *, s32, s32);
void Stats_CalcBase_0_001D08E0(u16 *, u8 *, s16 *, C4 *);
void Stats_CalcDefense_0_001D0000(u16 *, u8 *, u16 *, s16 *, C4 *, s32);
s32 Player_GetStat_2_001CD450(s32, u8 *, s32, s32);
static inline f32 u2f(u32 x) { return x; }
static inline s32 getid(s32 i) {
    S *r = PlayerData_Get_2_001C9BA0();
    if (i >= 0 && i < 10) return r->x80[i];
    return -1;
}
static inline s32 pct(u16 *p, f32 k) { return (u32)(k * (f32)(u32)*p); }
static inline u32 fl(S *r) {
    if (r->x60 == 0 && r->x40 != 0) return r->x40 >> 24;
    return 0;
}

void Player_RecalcStats_1_001CEDC0(s32 arg) {
    S *s;
    Q *q;
    S *r;
    E *tbl;
    s32 i;
    s32 k;
    s32 sum;
    u32 n;
    s32 idx;
    s32 id;
    u16 v;
    u8 c;
    s16 *h;
    C4 buf[10];

    s = PlayerData_Get_2_001C9BA0();
    q = Player_GetBodyState_1_001C9B60();
    if (q == NULL) return;
    memset(buf, 0, 0x28);
    for (i = 0; i < 10; i++) {
        k = s->x80[i];
        if (k != -1) {
            buf[i] = s->col[k];
        }
    }
    Stats_CalcBase_0_001D08E0(q->x460, q->x4A0, s->x80, buf);
    h = s->x80;
    if ((h[2] == 0x84 || h[2] == 0x85) && h[3] == 0xEF && (h[4] == 0x14B || h[4] == 0x14C) &&
        (h[5] == 0x1B0 || h[5] == 0x1B1)) {
        for (i = 0; i < 8; i++) {
            q->x460[i] = *(volatile u16 *)&q->x460[i] + pct(&q->x460[i], 0.1f);
            if ((s16)q->x460[i] < 0) q->x460[i] = 0;
            if ((s16)q->x460[i] > 999) q->x460[i] = 999;
        }
    }
    r = PlayerData_Get_2_001C9BA0();
    if (fl(r)) {
        q->x460[0] >>= 1;
        q->x460[1] >>= 1;
        q->x460[2] >>= 1;
        q->x460[3] >>= 1;
        q->x460[4] >>= 1;
        q->x460[5] >>= 1;
        q->x460[6] >>= 1;
        q->x460[7] >>= 1;
    }
    Stats_CalcDefense_0_001D0000(q->x470, q->x480, q->x460, s->x80, buf, arg);
    for (i = 0; i < 6; i++) {
        if (s->x70[i] != 0) {
            q->x470[i] = *(volatile u16 *)&q->x470[i] + pct(&q->x470[i], 0.5f);
            if ((s16)q->x470[i] < 0) q->x470[i] = 0;
            if ((s16)q->x470[i] > 999) q->x470[i] = 999;
        }
    }
    q->x41A = (u32)(500.0f + 0.04f * u2f((u16)s->x0));
    r = PlayerData_Get_2_001C9BA0();
    tbl = Item_GetTable_1_001AFC90();
    sum = 0;
    for (n = 0; n < 0x400; n++) {
        sum += r->col[n].c * tbl[n].x4;
    }
    if (Player_GetStat_2_001CD450(0xF, &c, 0, 1)) {
        sum -= sum * c / 100;
    }
    if (sum < 0) sum = 0;
    if (sum > 999) sum = 999;
    q->x418 = sum;
    v = q->x460[0] * 4 + 500 + (q->x460[1] + q->x460[2] + q->x460[3]) * 2;
    if ((s16)v < 0) v = 0;
    if ((s16)v > 9999) v = 9999;
    s->x0 = v;
    v = q->x460[4] * 4 + 500 + (q->x460[5] + q->x460[6] + q->x460[7]) * 2;
    if ((s16)v < 0) v = 0;
    if ((s16)v > 9999) v = 9999;
    s->x2 = v;
    if (s->x4 < 0) s->x4 = 0;
    if (s->x0 < s->x4) s->x4 = s->x0;
    if (s->x6 < 0) s->x6 = 0;
    if (s->x2 < s->x6) s->x6 = s->x2;
    id = getid(s->x94_ & 1);
    tbl = Item_GetTable_1_001AFC90();
    idx = (s16)id;
    q->x39C = (idx == -1) ? 0 : tbl[idx].x20;
}

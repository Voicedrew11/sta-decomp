#include "common.h"
typedef struct { u8 pad[8]; s32 x8; u8 pC[0x4C]; s32 x58; s32 x5C; u8 p60[0x28]; s32 x88; u8 p8C[0x1C]; s32 xA8; } P;
typedef struct { u8 data[0x50000]; s32 rd; s32 cnt; s32 size; } B;
typedef struct { s32 x0; s32 x4; s32 x8; } Q;
void RotateThreadReadyQueue(s32);
s32 SignalSema(s32);
s32 WaitSema(s32);
s32 func_00108DD8(P *, u8 *, s32, B *, s32);
s32 func_00116360(s32, s32, s32, ...);
void func_001D87F0(s32, u16, u16);
s32 func_001E8710(Q *, u8 *, s32, s32);
s32 func_001EA0D0(P *);
void func_001EBB70(s32 *);
s32 sceGsSyncV(s32);
s32 sceMpegIsRefBuffEmpty(P *);
extern s32 D_00201E70;
extern s32 D_002023EC;
extern s32 D_002023F0;
extern s32 D_00202400;
extern s8 D_004BD313[];
extern s32 D_004BD314[];
extern s32 D_004BD318[];
extern s32 D_004BDECC[];
extern s32 D_004BDED0[];
extern s32 D_004BDEE0[];
extern s32 D_004BDF24[];
extern s32 D_004BDF28[];
extern s32 D_004BDF34[];
extern s32 D_004BDFE8[];
extern s32 D_004BE0D0[];

static inline s32 notz(s32 x) { return !(x != 0); }
static inline s32 imin(s32 a, s32 b) {
    if (a < b) return a;
    return b;
}

s32 func_001ECAB0(P *p, B *buf, Q *q, s32 (*cb)(void)) {
    u8 *src;
    s32 started;
    s32 rem2;
    s32 trig;
    s32 rem;
    u32 v;
    u8 *dst;
    s32 n;
    s32 m;
    s32 d;
    s32 c;
    s32 ok;
    s32 done;

    started = 0;
    trig = 0;
    rem = q->x4;
    rem2 = rem;
    while (rem2 > 4 && p->xA8 != 3) {
        if (cb != NULL && trig == 0 && p->x8 > 10 && cb() != 0) {
            trig = 1;
            *D_004BD318 = p->x8;
        }
        if (trig != 0 && p->x8 > 10) {
            d = p->x8 - *D_004BD318;
            if (*D_004BD314 == 0 || d >= *D_004BD314) {
                *D_004BDFE8 = 1;
            } else {
                *D_004BD313 = d * 127 / *D_004BD314;
                if (D_00201E70 != 0) {
                    v = *D_004BE0D0 - (u32)(*D_004BE0D0 * d) / (u32)*D_004BD314;
                    if (v > 0x3FFF) v = 0;
                    func_001D87F0(0, v, v);
                    func_001D87F0(1, v, v);
                }
            }
        }
        c = buf->size - buf->cnt;
        if (c != 0) src = buf->data + buf->rd;
        if (rem > 0 && c >= 0x10000) {
            n = func_001E8710(q, src, 0x10000, q->x8 + (q->x4 - rem) / 0x800);
            m = imin(n, buf->size - buf->cnt);
            rem -= n;
            buf->rd = (buf->rd + m) % buf->size;
            buf->cnt += m;
        }
        RotateThreadReadyQueue(1);
        c = buf->cnt;
        if (c != 0) dst = buf->data + (buf->size + (buf->rd - c)) % buf->size;
        if (c > 0) {
            n = func_00108DD8(p, dst, c, buf, buf->size);
            m = imin(n, buf->cnt);
            rem2 -= n;
            buf->cnt -= m;
        }
        if (started == 0 && *D_004BDECC == *D_004BDED0) {
            if (D_00201E70 != 0) ok = !(*D_004BDF34 < *D_004BDF28); else ok = 1;
            if (ok) {
                while (sceGsSyncV(0) == 1) {}
                D_002023EC = 1;
                D_00202400 = 0;
                D_002023F0 = 0;
                if (D_00201E70 != 0) {
                    func_00116360(1, 0x8010, 0x800, 0xC0);
                    func_00116360(1, 0x8010, 0x801, 0xC);
                    func_00116360(1, 0x80E0, 0, 0x10, *D_004BDF24, *D_004BDF28 / 1024 * 1024);
                    func_00116360(1, 0x8010, 0xF80, 0x7FFF);
                    func_00116360(1, 0x8010, 0x1080, 0x7FFF);
                    func_00116360(1, 0x8010, 0xF81, 0x7FFF);
                    func_00116360(1, 0x8010, 0x1081, 0x7FFF);
                    func_00116360(1, 0x8010, 0xD81, 0x7FFF);
                    func_00116360(1, 0x8010, 0xE81, 0x7FFF);
                    func_00116360(1, 0x8010, 0x980, *D_004BE0D0);
                    func_00116360(1, 0x8010, 0xA80, *D_004BE0D0);
                    func_00116360(1, 0x8010, 0x981, *D_004BE0D0);
                    func_00116360(1, 0x8010, 0xA81, *D_004BE0D0);
                    *D_004BDEE0 = 2;
                }
                started = 1;
            }
        }
    }
    while (notz(func_001EA0D0(p))) {
        RotateThreadReadyQueue(1);
    }
    goto check;
    do {
        RotateThreadReadyQueue(1);
check:
        v = 0;
        WaitSema(p->x88);
        rem = p->x5C + (p->x58 << 11);
        SignalSema(p->x88);
        if (rem == 0 && sceMpegIsRefBuffEmpty(p) != 0) v = 1;
    } while (v == 0 && p->xA8 != 3);
    D_002023EC = 0;
    D_00202400 = 0;
    if (D_00201E70 != 0) func_001EBB70(D_004BDEE0);
    return 1;
}


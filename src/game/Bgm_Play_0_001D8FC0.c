#include "common.h"

typedef struct { u8 pad[0xC]; u32 n; u8 pad1[4]; u8 v; s8 pan; u8 pad2[0xA]; s32 off[1]; } Tbl;
typedef struct { u32 n; u8 pad[4]; u8 v; s8 pan; u8 pad2[6]; s32 off[1]; } Ent;
typedef struct { s32 off; u8 v; s8 pan; u8 pad[2]; s32 len; } Rec;
typedef struct { u8 pad[0x28]; s32 off; } Hdr;
typedef struct { u8 pad[0xC]; s16 r; s16 l; } Out;

s32 Bgm_FindTrack_0_001D9470(s32, s32, s32, u32, u32, u32, Out *);

static inline s32 isz(s32 x) { return !(x != 0); }

s32 Bgm_Play_0_001D8FC0(s32 a0, s32 a1, s32 a2, s32 a3, u32 i, u32 j, Out *out) {
    s32 ch = -1;
    s32 b1 = -1;
    s32 b2 = -1;
    Tbl *t;
    Ent *e;
    Rec *r;
    u8 *p;
    s32 len;
    u8 *start;
    u8 c;
    s32 R, L, R2, L2, L3, R3;
    s32 fl, fr, lr, rr;
    s32 v;
    s8 pan;

    if (isz(a2 & (a0 & a1)))
        return 0;
    t = (Tbl *)(a0 + ((Hdr *)a0)->off);
    if (t->n < i)
        return 0;
    e = (Ent *)((u8 *)t + t->off[i]);
    if (e->n < j)
        return 0;
    r = (Rec *)((u8 *)t + e->off[j]);
    p = (u8 *)r + r->off;
    len = r->len;
    start = p;
    if (0 < len) {
        do {
            while (*p++ & 0x80) {}
            c = *p;
            if (c == 0xFF)
                break;
            if ((c & 0xF0) == 0x80 || (c & 0xF0) == 0x90) {
                b1 = p[1];
                b2 = p[2];
                ch = c & 0xF;
                p += 4;
            } else {
                p += 3;
                switch (*p) {
                case 7:
                case 12:
                case 13:
                    while (*p++ & 0x80) {}
                    p += 1;
                    break;
                case 14:
                case 15:
                    while (*p++ & 0x80) {}
                    p += 2;
                    break;
                case 16:
                case 17:
                    p += 2;
                    break;
                case 18:
                case 34:
                    while (*p++ & 0x80) {}
                    break;
                case 32:
                case 33:
                    p += 1;
                    break;
                default:
                    return 0;
                }
            }
        } while (p - start < len);
    }
    if (ch == -1)
        return 0;

    v = t->v;
    pan = t->pan;
    L = v * 0x3FFF / 127;
    R = L;
    if (pan >= 0) {
        if (pan < 0x41)
            L = L * pan >> 6;
        else
            R = L * (0x7F - pan) >> 6;
    } else {
        if (pan >= -0x40)
            L = L * pan >> 6;
        else
            R = L * (-0x7F - pan) >> 6;
    }
    L2 = e->v;
    pan = e->pan;
    R2 = L2;
    if (pan >= 0) {
        if (pan < 0x41)
            L2 = L2 * pan >> 6;
        else
            R2 = L2 * (0x7F - pan) >> 6;
    } else {
        if (pan >= -0x40)
            L2 = L2 * pan >> 6;
        else
            R2 = L2 * (-0x7F - pan) >> 6;
    }
    L3 = r->v;
    pan = r->pan;
    R3 = L3;
    if (pan >= 0) {
        if (pan < 0x41)
            L3 = L3 * pan >> 6;
        else
            R3 = L3 * (0x7F - pan) >> 6;
    } else {
        if (pan >= -0x40)
            L3 = L3 * pan >> 6;
        else
            R3 = L3 * (-0x7F - pan) >> 6;
    }
    lr = L * L2;
    rr = R * R2;
    fr = R3 * rr / 16129;
    fl = L3 * lr / 16129;
    out->r = fr < 0 ? ((-fr & 0x3FFF) | 0x4000) : (fr & 0x3FFF);
    out->l = fl < 0 ? ((-fl & 0x3FFF) | 0x4000) : (fl & 0x3FFF);
    return Bgm_FindTrack_0_001D9470(a1, a2, a3, ch, b1, b2, out);
}

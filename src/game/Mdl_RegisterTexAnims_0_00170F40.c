#include "m2c.h"
typedef struct { s32 a; u16 w; u16 h; } Ent;
typedef struct { u8 pad[0x10]; s32 *base; u16 n14; u16 n16; u16 n18; u16 n1A; u16 n1C; u16 n1E; u16 count; u8 pad2[0x1A]; u8 flags; u8 p3[3]; } Hdr;
typedef struct { u8 b[16]; } B16; typedef struct { u8 b[8]; } B8; typedef struct { u8 b[4]; } B4; typedef struct { u8 b[0x50]; } B50;
void TexAnim_Register_0_001759D0(s32, u32, s32, s32 *);

void Mdl_RegisterTexAnims_0_00170F40(Hdr **arg0) {
    Hdr *h;
    s32 base;
    s32 i;
    Ent *e;
    s8 *d;
    i = 0;
    h = *arg0;
    base = *h->base;
    d = (s8*)(h + 1); d = (s8*)((B16*)d + h->n14); e = (Ent*)(d + h->n16 * 8 + h->n18 * 4 + h->n1C * 0x50 + h->n1E * 4);
    for (; i < h->count; i++, e++) {
        if (((u64)((s64)h->flags << 0x3B) >> 0x3F) != 0) {
            TexAnim_Register_0_001759D0(e->w, e->h, base + e->a, h->base);
        } else {
            TexAnim_Register_0_001759D0(e->w, e->h, base + e->a, 0);
        }
    }
}

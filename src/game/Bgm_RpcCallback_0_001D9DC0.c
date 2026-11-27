#include "common.h"

extern s32 D_0020231C;
s32 Bgm_DmaChunk_0_001D9BC0(s32 a, s32 b, s32 c, s32 d);

s32 *Bgm_RpcCallback_0_001D9DC0(u32 cmd, s32 *p, s32 unused, s32 *size)
{
    switch (cmd & 0xFFF0000) {
    case 0x2040000:
        D_0020231C = Bgm_DmaChunk_0_001D9BC0(p[0], p[1], p[2], p[3]);
        break;
    }
    *size = 4;
    return &D_0020231C;
}

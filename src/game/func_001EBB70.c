#include "common.h"

s32 sceSdRemote(s32, s32, s32, ...);

s32 func_001EBB70(s32 *p)
{
    sceSdRemote(1, 0x8010, 0xF80, 0);
    sceSdRemote(1, 0x8010, 0x1080, 0);
    sceSdRemote(1, 0x8010, 0xF81, 0);
    sceSdRemote(1, 0x8010, 0x1081, 0);
    sceSdRemote(1, 0x8010, 0xD81, 0);
    sceSdRemote(1, 0x8010, 0xE81, 0);
    sceSdRemote(1, 0x8010, 0x980, 0);
    sceSdRemote(1, 0x8010, 0xA80, 0);
    sceSdRemote(1, 0x8010, 0x981, 0);
    sceSdRemote(1, 0x8010, 0xA81, 0);
    sceSdRemote(1, 0x80E0, 0, 2, 0, 0);
    sceSdRemote(1, 0x80E0, 1, 2, 0, 0);
    p[0] = 0;
    p[11] = 0;
    p[13] = 0;
    p[14] = 0;
    p[16] = 0;
    p[21] = 0;
    p[19] = 0;
    p[20] = 0;
    return 0;
}

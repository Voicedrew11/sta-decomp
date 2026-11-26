#include "common.h"
extern struct { char pad[0x80]; s32 port; s32 slot; s32 state; s32 sub; s32 x90; s32 x94; s32 x98; s32 retry; s32 path; s32 pwd; } D_004B63B8;
s32 sceMcChdir(s32, s32, s32, s32);
s32 sceMcSync(s32, s32 *, s32 *);

s32 func_001D6550(void)
{
    s32 r;
    s32 port = D_004B63B8.port;
    s32 slot = D_004B63B8.slot;

    switch (D_004B63B8.sub) {
    case 0:
        D_004B63B8.sub = 1;
        D_004B63B8.retry = 0;
        break;
    case 1:
        if (sceMcChdir(port, slot, D_004B63B8.path, D_004B63B8.pwd) != 0) {
            if (D_004B63B8.retry == 2) {
                D_004B63B8.x98 = 100;
                return -10;
            }
            D_004B63B8.retry++;
        } else {
            D_004B63B8.sub++;
        }
        break;
    case 2:
        if (sceMcSync(1, 0, &r) == 0) break;
        if (r == 0) {
            D_004B63B8.state = 0;
            D_004B63B8.x98 = 0;
            return 1;
        }
        if (D_004B63B8.retry == 2) {
            D_004B63B8.state = 0;
            if (r == -2) D_004B63B8.x98 = 3; else D_004B63B8.x98 = 100;
            return r;
        }
        D_004B63B8.retry++;
        D_004B63B8.sub--;
        break;
    }
    return 0;
}

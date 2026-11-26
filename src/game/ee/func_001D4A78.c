#include "common.h"

typedef struct {
    s32 type[2][4];
    s32 free[2][4];
    s32 format[2][4];
    char pad60[0x20];
    s32 port; s32 slot; s32 x88; s32 state;
    s32 x90; s32 x94; s32 x98; s32 x9c;
    s32 name; s32 xa4; u32 xa8; s32 xac; s32 xb0; s32 xb4;
} T;
extern T D_004B63B8;
extern s32 D_004B638C[];
extern s32 D_004B6390[];
extern s32 D_004B6394[];
extern s32 D_004B6398[];
extern s32 D_004B6474[];
extern u8 D_004B6478[];
s32 func_001D3BF0(s32, s32, s32 *, s32 *, s32 *, s32);
s32 func_001D3CE0(s32);
void func_001D3DA8(s32);
void *memcpy(void *, void *, s32);
void memset(void *, s32, s32);
s32 sceMcOpen(s32, s32, s32, s32);
s32 sceMcClose(s32);
s32 sceMcRead(s32, void *, s32);
s32 sceMcSeek(s32, s32, s32);
s32 sceMcSync(s32, s32 *, s32 *);

s32 func_001D4A78(void)
{
#define t (&D_004B63B8)
    s32 r;
    s32 v;
    s32 port = t->port;
    s32 slot = t->slot;
    s32 max;
    s32 len;
    s32 i;
    u8 sum;
    s32 d;
    s32 a;
    s32 x;

    switch (t->state) {
    case 0:
        D_004B6474[0] = -1;
        t->state++;
        t->x9c = 0;
        D_004B638C[0] = 0;
    case 1:
        v = func_001D3BF0(port, slot, &t->type[port][slot], &t->free[port][slot], &t->format[port][slot], t->x90);
        t->x90 = v;
        if (v > 0) break;
        v = func_001D3CE0(v);
        t->x98 = v;
        if (v != 0) {
            t->x88 = 0;
            return -10;
        }
        if (t->type[port][slot] != 2) {
            if (t->type[port][slot] == 3) t->x98 = 1;
            else t->x98 = 1;
            t->x88 = 0;
            return -10;
        }
        t->x9c = 0;
        t->state++;
        break;
    case 2:
        if (sceMcOpen(port, slot, t->name, 1) != 0) {
            if (t->x9c == 2) {
                t->x88 = 0;
                t->x98 = 0x47;
                return -10;
            }
            t->x9c++;
        } else {
            t->state++;
        }
        break;
    case 3:
        if (sceMcSync(1, 0, &r) != 0) {
            if (r < 0) {
                if (t->x9c == 2) {
                    func_001D3DA8(r);
                    if (t->x98 == 100) {
                        t->x98 = 0x47;
                    }
                    t->x88 = 0;
                    return r;
                } else {
                    t->x9c++;
                    t->state--;
                }
            } else {
                D_004B6474[0] = r;
                t->x9c = 0;
                t->state++;
            }
        }
        break;
    case 4:
        v = sceMcRead(D_004B6474[0], D_004B6390, 4);
        if (v != 0) {
            if (t->x9c == 2) {
                t->x98 = 0x47;
                t->state = 100;
            } else {
                t->x9c++;
            }
        } else {
            t->state++;
        }
        break;
    case 5:
        if (sceMcSync(1, 0, &r) != 0) {
            if (r < 0) {
                if (t->x9c == 2) {
                    t->x98 = 0x47;
                    t->state = 100;
                } else {
                    t->x9c++;
                    t->state--;
                }
            } else {
                t->state++;
            }
        }
        break;
    case 6:
        x = D_004B6390[0];
        D_004B6398[0] = x + 6;
        x -= 0x3FB;
        if (x > 0) {
            D_004B6398[0] += (x + 0x3FE) / 0x3FF;
        }
        a = (D_004B6398[0] + 0x1F) & ~0x1F;
        d = D_004B6398[0] - 1;
        t->state++;
        D_004B6398[0] = a;
        D_004B6394[0] = d - a + 0x20;
        t->x9c = 0;
        break;
    case 7:
        v = sceMcSeek(D_004B6474[0], D_004B6398[0] - 0x20, 0);
        if (v != 0) {
            if (t->x9c == 2) {
                t->x98 = 0x47;
                t->state = 100;
            } else {
                t->x9c++;
            }
        } else {
            t->state++;
        }
        break;
    case 8:
        if (sceMcSync(1, 0, &r) != 0) {
            if (r < 0) {
                if (t->x9c == 2) {
                    t->x98 = 0x47;
                    t->state = 100;
                } else {
                    t->x9c++;
                    t->state--;
                }
            } else {
                t->x9c = 0;
                t->state++;
            }
        }
        break;
    case 9:
        v = sceMcRead(D_004B6474[0], D_004B6478, 0x20);
        if (v != 0) {
            if (t->x9c == 2) {
                t->x98 = 0x47;
                t->state = 100;
            } else {
                t->x9c++;
            }
        } else {
            t->state++;
        }
        break;
    case 10:
        if (sceMcSync(1, 0, &r) != 0) {
            if (r < 0) {
                if (t->x9c == 2) {
                    t->x98 = 0x47;
                    t->state = 100;
                } else {
                    t->x9c++;
                    t->state--;
                }
            } else {
                if (D_004B6478[D_004B6394[0]] != 1) {
                    t->x98 = 0x47;
                    t->state = 100;
                } else {
                    t->x9c = 0;
                    t->state++;
                }
            }
        }
        break;
    case 11:
        v = sceMcSeek(D_004B6474[0], 4, 0);
        if (v != 0) {
            if (t->x9c == 2) {
                t->x98 = 0x47;
                t->state = 100;
            } else {
                t->x9c++;
            }
        } else {
            t->state++;
        }
        break;
    case 12:
        if (sceMcSync(1, 0, &r) != 0) {
            if (r < 0) {
                if (t->x9c == 2) {
                    t->x98 = 0x47;
                    t->state = 100;
                } else {
                    t->x9c++;
                    t->state--;
                }
            } else {
                t->state++;
                memset(D_004B6478, 0, 0x400);
                t->x9c = 0;
            }
        }
        break;
    case 13:
        len = D_004B638C[0] == 0 ? 0x3FC : 0x400;
        v = sceMcRead(D_004B6474[0], D_004B6478, len);
        if (v != 0) {
            if (t->x9c == 2) {
                t->x98 = 0x47;
                t->state = 100;
            } else {
                t->x9c++;
            }
        } else {
            t->state++;
        }
        break;
    case 14:
        if (sceMcSync(1, 0, &r) != 0) {
            if (r < 0) {
                if (t->x9c == 2) {
                    if (r == -2) t->x98 = 3;
                    else if (r < -10) t->x98 = 1;
                    else t->x98 = 0x47;
                    t->x90 = r;
                    t->state = 100;
                } else {
                    t->x9c++;
                    t->state--;
                }
            } else {
                max = D_004B638C[0] ? 0x3FF : 0x3FB;
                len = D_004B6390[0] - D_004B638C[0];
                if (max < len) len = max;
                if (len != 0) {
                    sum = 0;
                    for (i = 0; i < len; i++) {
                        sum += ~D_004B6478[i];
                    }
                    if (sum == D_004B6478[len]) {
                        if (t->xa8 < (u32)D_004B6390[0]) {
                            len = t->xa8 - D_004B638C[0];
                        } else {
                            len = D_004B6390[0] - D_004B638C[0];
                        }
                        if (max < len) len = max;
                        memcpy((void *)(t->xb4 + D_004B638C[0]), D_004B6478, len);
                        if (len < max) {
                            t->state++;
                            break;
                        }
                    } else {
                        t->x90 = -399;
                        t->x98 = 0x47;
                        t->state = 100;
                        break;
                    }
                }
                D_004B638C[0] += len;
                t->x9c = 0;
                t->state--;
            }
        }
        break;
    case 15:
        t->x9c = 0;
        t->state++;
        break;
    case 16:
        if (sceMcClose(D_004B6474[0]) != 0) {
            if (t->x9c == 2) {
                t->x88 = 0;
                t->x98 = 0x47;
                return -100;
            }
            t->x9c++;
        } else {
            t->state++;
        }
        break;
    case 17:
        if (sceMcSync(1, 0, &r) != 0) {
            if (r < 0) {
                if (t->x9c == 2) {
                    t->x88 = 0;
                    t->x98 = 0x47;
                    return r;
                }
                t->x9c++;
                t->state--;
            } else {
                t->x98 = 0x48;
                t->x88 = 0;
                return 1;
            }
        }
        break;
    case 100:
        if (D_004B6474[0] < 0) {
            t->x88 = 0;
            return -100;
        }
        t->x9c = 0;
        t->state++;
        break;
    case 101:
        if (sceMcClose(D_004B6474[0]) != 0) {
            if (t->x9c == 2) {
                t->x98 = 0x47;
                return -1;
            }
            t->x9c++;
        } else {
            t->state++;
        }
        break;
    case 102:
        if (sceMcSync(1, 0, &r) != 0) {
            t->x88 = 0;
            return -200;
        }
        break;
    }
    return 0;
}

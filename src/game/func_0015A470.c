#include "m2c.h"
typedef struct { s32 x0; volatile u32 x4; s32 x8; s32 xC; u16 flags; s32 fd; s32 size; } F;
extern F *D_00201F80;
extern s32 D_00201F88;
extern s32 D_00201F8C;
void func_0010FED8(s32, s32, s32);
void func_00110110(s32, u8 *, s32);
s32 func_0015A3A0(F *, s32);
void func_00123C40(void *, s32, s32);
void func_00123A88(void *, void *, s32);
s32 func_001178E8(u32, s32, void *, u8 *);
s32 func_00117AC8(void);
static inline void seek(F *f) {
    switch ((s32)f->flags) {
    case 0x100:
    case 0x200:
    case 0x101:
    case 0x201:
        break;
    case 0:
        func_0010FED8(D_00201F80->fd, f->x4, 0);
        break;
    case 1:
        func_0010FED8(f->fd, f->x4, 0);
        break;
    }
}
static inline void seek2(F *f) {
    switch ((s32)*(volatile u16 *)&f->flags) {
    case 0x100:
    case 0x200:
    case 0x101:
    case 0x201:
        break;
    case 0:
        func_0010FED8(D_00201F80->fd, f->x4, 0);
        break;
    case 1:
        func_0010FED8(f->fd, f->x4, 0);
        break;
    }
}

s32 func_0015A470(F *f, u8 *buf, s32 n, s32 mode) {
    u8 sec[0x800];
    u8 sec2[0x800];
    u8 st[4];
    s32 rem;
    s32 cnt;
    s32 res;
    s32 ns;
    s32 off;

    rem = f->size - (f->x4 - f->x0);
    cnt = n;
    if (rem <= 0) {
        return 0;
    }
    if (rem < n) {
        cnt = rem;
    }
    if ((f->flags & 1) && f->fd >= 0) {
        if (mode) {
            seek(f);
            func_00110110(f->fd, buf, n);
            func_0015A3A0(f, mode);
            f->x4 += n;
        } else {
            seek(f);
            func_00110110(f->fd, buf, (cnt + 0x7FF) & ~0x7FF);
            f->x4 += cnt;
        }
        return rem;
    }
    if (D_00201F88) {
        if (D_00201F8C) {
            return rem;
        }
        if (D_00201F80->fd >= 0) {
            if (mode) {
                seek2(f);
                func_00110110(D_00201F80->fd, buf, n);
                func_0015A3A0(f, mode);
                f->x4 += n;
            } else {
                seek2(f);
                D_00201F8C = 1;
                func_00110110(D_00201F80->fd, buf, (cnt + 0x7FF) & ~0x7FF);
                f->x4 += cnt;
            }
        }
    } else {
    func_00123C40(st, 0, 4);
    st[0] = 0;
    st[1] = 1;
    st[2] = 0;
    st[3] = 0;
    if (!mode) goto nm;
    {
        res = 0;
        off = f->x4 & 0x7FF;
        if (off) {
            cnt = 0x800 - off;
            if (rem < cnt) {
                cnt = rem;
            }
            if (n < cnt) {
                cnt = n;
            }
            func_00123C40(st, 0, 4);
            st[0] = 0;
            st[1] = 1;
            st[2] = 0;
            st[3] = 0;
            do {
                while (func_001178E8(f->x4 >> 11, 1, sec, st) == 0) {
                }
                if (!func_0015A3A0(f, mode)) {
                    res = func_00117AC8();
                }
            } while (res != 0 && res != 1);
            func_00123A88(buf, sec + (f->x4 & 0x7FF), cnt);
            f->x4 += cnt;
            rem -= cnt;
            buf += cnt;
            n -= cnt;
            if (rem == 0) {
                return 0;
            }
            if (n == 0) {
                return rem;
            }
        }
        cnt = (n / 0x800) << 11;
        if (rem < cnt) {
            cnt = rem;
        }
        if (n < cnt) {
            cnt = n;
        }
        if (cnt) {
            ns = cnt / 0x800;
            do {
                while (func_001178E8(f->x4 >> 11, ns, buf, st) == 0) {
                }
                if (!func_0015A3A0(f, mode)) {
                    res = func_00117AC8();
                }
            } while (res != 0 && res != 1);
        }
        f->x4 += cnt;
        rem -= cnt;
        buf += cnt;
        n -= cnt;
        if (rem == 0) {
            return 0;
        }
        if (n == 0) {
            return rem;
        }
        if (n) {
            func_00123C40(st, 0, 4);
            st[0] = 0;
            st[1] = 1;
            st[2] = 0;
            st[3] = 0;
            do {
                while (func_001178E8(f->x4 >> 11, 1, sec2, st) == 0) {
                }
                if (!func_0015A3A0(f, mode)) {
                    res = func_00117AC8();
                }
            } while (res != 0 && res != 1);
            func_00123A88(buf, sec2, n);
            f->x4 += n;
            rem -= n;
            if (rem == 0) {
                return 0;
            }
            return rem;
        }
        rem = 0;
        goto out;
    }
rd:
    if (func_001178E8(f->x4 >> 11, n, buf, st) == 0) goto rd;
    f->x4 += cnt;
    }
out:
    return rem;
nm:
    n = ((cnt + 0x7FF) & ~0x7FF) / 0x800;
    goto rd;
}

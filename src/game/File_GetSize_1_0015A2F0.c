#include "common.h"
#include "m2c.h"
typedef struct { s32 x0; volatile u32 x4; s32 x8; s32 xC; u16 flags; s32 fd; s32 size; } F_File_Read_2_0015A470;
typedef struct { s32 x0; char p4[0x10]; s32 fd; s32 x18; } F_File_Close_2_0015AB80;
extern s32 D_00201F88;
extern s8 *D_00201F80;
extern s32 D_00201F8C;
void File_GetSize_1_0015A2F0(void *arg0, s32 *arg1);
s32 File_GetSectorOrSize_0_0015A300(void *arg0);
s32 File_GetOffset_0_0015A350(void *arg0);
s32 File_WaitRead_1_0015A3A0(s8 *a0, s32 a1);
s32 File_Read_2_0015A470(F_File_Read_2_0015A470 *f, u8 *buf, s32 n, s32 mode);
void File_Close_2_0015AB80(F_File_Close_2_0015AB80 *f);
s32 sceIoctl(s32, s32, s32 *);
s32 sceGsSyncV(s32);
s32 sceCdSync(s32);
void sceLseek(s32, s32, s32);
void sceRead(s32, u8 *, s32);
void memset(void *, s32, s32);
void memcpy(void *, void *, s32);
s32 sceCdRead(u32, s32, void *, u8 *);
s32 sceCdGetError(void);
s32 sceClose(s32 fd);

/* File_GetSize_1_0015A2F0 */
void File_GetSize_1_0015A2F0(void *arg0, s32 *arg1) {
    *arg1 = M2C_FIELD(arg0, s32 *, 0xC);
}

/* File_GetSectorOrSize_0_0015A300 */
s32 File_GetSectorOrSize_0_0015A300(void *arg0) {
    s32 temp_3;

    temp_3 = M2C_FIELD(arg0, u16 *, 0x10) & 1;
    switch (temp_3) {                               /* irregular */
    case 0:
        return M2C_FIELD(M2C_FIELD(arg0, void **, 0xC), s32 *, 0xC);
    case 1:
        return M2C_FIELD(arg0, s32 *, 0x18);
    default:
        return 0;
    }
}

/* File_GetOffset_0_0015A350 */
s32 File_GetOffset_0_0015A350(void *arg0) {
    s32 temp_3;

    temp_3 = M2C_FIELD(arg0, u16 *, 0x10) & 1;
    switch (temp_3) {                               /* irregular */
    case 0:
        return M2C_FIELD(M2C_FIELD(arg0, void **, 0xC), s32 *, 4);
    case 1:
        return M2C_FIELD(arg0, s32 *, 0x18);
    default:
        return 0;
    }
}

/* File_WaitRead_1_0015A3A0 */
s32 File_WaitRead_1_0015A3A0(s8 *a0, s32 a1) {
    s32 r = 1;
    if (D_00201F88) {
        if (!(*(u16 *)(a0 + 0x10) & 1)) a0 = D_00201F80;
        if (a1 == 0) {
            sceIoctl(*(s32 *)(a0 + 0x14), 1, &r);
            if (a0 == D_00201F80 && r == 0) D_00201F8C = 0;
        } else {
            do {
                sceIoctl(*(s32 *)(a0 + 0x14), 1, &r);
                sceGsSyncV(0);
            } while (r);
            if (a0 == D_00201F80) D_00201F8C = 0;
        }
    } else {
        r = sceCdSync(a1 != 1);
    }
    return r;
}

/* File_Read_2_0015A470 */
#define D_00201F80 D_00201F80__as_File_Read_2_0015A470
extern F_File_Read_2_0015A470 *D_00201F80__as_File_Read_2_0015A470;
#define File_WaitRead_1_0015A3A0 File_WaitRead_1_0015A3A0__as_File_Read_2_0015A470
s32 File_WaitRead_1_0015A3A0__as_File_Read_2_0015A470(F_File_Read_2_0015A470 *, s32);
static inline void seek(F_File_Read_2_0015A470 *f) {
    switch ((s32)f->flags) {
    case 0x100:
    case 0x200:
    case 0x101:
    case 0x201:
        break;
    case 0:
        sceLseek(D_00201F80->fd, f->x4, 0);
        break;
    case 1:
        sceLseek(f->fd, f->x4, 0);
        break;
    }
}
static inline void seek2(F_File_Read_2_0015A470 *f) {
    switch ((s32)*(volatile u16 *)&f->flags) {
    case 0x100:
    case 0x200:
    case 0x101:
    case 0x201:
        break;
    case 0:
        sceLseek(D_00201F80->fd, f->x4, 0);
        break;
    case 1:
        sceLseek(f->fd, f->x4, 0);
        break;
    }
}

s32 File_Read_2_0015A470(F_File_Read_2_0015A470 *f, u8 *buf, s32 n, s32 mode) {
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
            sceRead(f->fd, buf, n);
            File_WaitRead_1_0015A3A0(f, mode);
            f->x4 += n;
        } else {
            seek(f);
            sceRead(f->fd, buf, (cnt + 0x7FF) & ~0x7FF);
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
                sceRead(D_00201F80->fd, buf, n);
                File_WaitRead_1_0015A3A0(f, mode);
                f->x4 += n;
            } else {
                seek2(f);
                D_00201F8C = 1;
                sceRead(D_00201F80->fd, buf, (cnt + 0x7FF) & ~0x7FF);
                f->x4 += cnt;
            }
        }
    } else {
    memset(st, 0, 4);
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
            memset(st, 0, 4);
            st[0] = 0;
            st[1] = 1;
            st[2] = 0;
            st[3] = 0;
            do {
                while (sceCdRead(f->x4 >> 11, 1, sec, st) == 0) {
                }
                if (!File_WaitRead_1_0015A3A0(f, mode)) {
                    res = sceCdGetError();
                }
            } while (res != 0 && res != 1);
            memcpy(buf, sec + (f->x4 & 0x7FF), cnt);
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
                while (sceCdRead(f->x4 >> 11, ns, buf, st) == 0) {
                }
                if (!File_WaitRead_1_0015A3A0(f, mode)) {
                    res = sceCdGetError();
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
            memset(st, 0, 4);
            st[0] = 0;
            st[1] = 1;
            st[2] = 0;
            st[3] = 0;
            do {
                while (sceCdRead(f->x4 >> 11, 1, sec2, st) == 0) {
                }
                if (!File_WaitRead_1_0015A3A0(f, mode)) {
                    res = sceCdGetError();
                }
            } while (res != 0 && res != 1);
            memcpy(buf, sec2, n);
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
    if (sceCdRead(f->x4 >> 11, n, buf, st) == 0) goto rd;
    f->x4 += cnt;
    }
out:
    return rem;
nm:
    n = ((cnt + 0x7FF) & ~0x7FF) / 0x800;
    goto rd;
}
#undef File_WaitRead_1_0015A3A0
#undef D_00201F80

/* File_Close_2_0015AB80 */
void File_Close_2_0015AB80(F_File_Close_2_0015AB80 *f)
{
    if (f->fd >= 0) {
        sceClose(f->fd);
        f->fd = -1;
    }
    f->x18 = 0;
    f->x0 = 0;
}

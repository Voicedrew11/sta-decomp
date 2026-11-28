#include "m2c.h"
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; u16 flags; s16 x12; s32 fd; s32 size; } F_Arc_FindByHash_2_0015ABD0;
typedef struct { u8 c[4]; s32 x4; s32 x8; s32 xC; s32 x10; s32 x14; s32 x18; s32 x1C; } E;
typedef struct { s32 a, b, n, c; E e[1]; } T;
typedef struct { s32 x0; volatile s32 x4; s32 x8; s32 xC; u16 flags; s32 fd; s32 size; } F_Arc_Mount_2_0015AD00;
extern s32 D_00201C7C;
extern F_Arc_FindByHash_2_0015ABD0 *D_00201F80;
extern s32 D_00201F88;
extern T D_002F20C0;
extern s32 D_002F20C8[];
extern F_Arc_FindByHash_2_0015ABD0 D_0030A0D0[];
extern s8 D_001FB740[];
extern s8 D_001FB748[];
extern s8 D_001FB750[];
extern s8 D_001FB758[];
extern s8 D_001FB760[];
extern s32 D_002F20C4[];
F_Arc_FindByHash_2_0015ABD0* Arc_FindByHash_2_0015ABD0(s32 key);
void Arc_Mount_2_0015AD00(s8 *arg0, s32 arg1, s32 arg2);
s32 sceOpen(s8 *, s32, s32);
void sceLseek(s32, s32, s32);
void sceCdSearchFile(s32 *, s8 *);
void memset(void *, s32, s32);
void sprintf(s8 *, s8 *, s8 *, s8 *, s8 *);
void strcat(s8 *, s8 *);
void strcpy(s8 *, s8 *);
void File_Read_2_0015A470(F_Arc_Mount_2_0015AD00 *, s8 *, s32, s32);
void Cd_Init_2_0015B040(s32, s32);

/* Arc_FindByHash_2_0015ABD0 */
static inline F_Arc_FindByHash_2_0015ABD0 *findFree_Arc_FindByHash_2_0015ABD0(void) {
    s32 i;
    for (i = 0; i < 16; i++) {
        if (D_0030A0D0[i].size == 0) {
            return &D_0030A0D0[i];
        }
    }
    return NULL;
}

F_Arc_FindByHash_2_0015ABD0 *Arc_FindByHash_2_0015ABD0(s32 key) {
    s32 n;
    E *e;
    s32 i;
    F_Arc_FindByHash_2_0015ABD0 *f;

    n = D_002F20C8[0];
    e = NULL;
    if (D_00201C7C == 3 && D_00201F88 == 0) {
        return NULL;
    }
    for (i = 0; i < n; i++) {
        e = &D_002F20C0.e[i];
        if (key == e->x14) break;
    }
    if (i == n) {
        return NULL;
    }
    f = findFree_Arc_FindByHash_2_0015ABD0();
    f->x0 = D_00201F80->x0 + (e->x18 << 11);
    f->x4 = f->x0;
    f->x8 = e->x14;
    f->xC = (s32)e;
    f->flags = D_00201F80->flags;
    f->flags &= 0x300;
    f->x12 = e->c[3] - 0x30;
    f->fd = -1;
    f->size = e->x8;
    return f;
}

/* Arc_Mount_2_0015AD00 */
#define D_00201F80 D_00201F80__as_Arc_Mount_2_0015AD00
extern F_Arc_Mount_2_0015AD00 *D_00201F80__as_Arc_Mount_2_0015AD00;
#define D_002F20C0 D_002F20C0__as_Arc_Mount_2_0015AD00
extern s8 D_002F20C0__as_Arc_Mount_2_0015AD00[];
#define D_0030A0D0 D_0030A0D0__as_Arc_Mount_2_0015AD00
extern F_Arc_Mount_2_0015AD00 D_0030A0D0__as_Arc_Mount_2_0015AD00[];
static inline F_Arc_Mount_2_0015AD00 *findFree_Arc_Mount_2_0015AD00(void) {
    s32 i;
    for (i = 0; i < 16; i++) {
        if (D_0030A0D0[i].size == 0) {
            return &D_0030A0D0[i];
        }
    }
    return NULL;
}

void Arc_Mount_2_0015AD00(s8 *arg0, s32 arg1, s32 arg2) {
    s8 path[0x100];
    s8 name[0x100];
    s32 st[12];
    s32 mode;
    s8 *p;
    s8 c;
    F_Arc_Mount_2_0015AD00 *f;

    mode = arg1 & 0x300;
    D_00201F88 = mode == 0;
    D_00201C7C = arg1 & 3;
    Cd_Init_2_0015B040(mode, 0);
    D_00201F80 = findFree_Arc_Mount_2_0015AD00();
    if (D_00201F88 != 0) {
        strcpy(name, arg0);
        c = name[0];
        p = name;
        if (c != 0) {
            do {
                if (c == 0x5C) {
                    *p = 0x2F;
                }
                p++;
                c = *p;
            } while (c != 0);
        }
        sprintf(path, D_001FB740, D_001FB748, D_001FB750, name + 1);
        D_00201F80->x0 = 0;
        D_00201F80->x4 = 0;
        D_00201F80->x8 = 0;
        D_00201F80->xC = 0;
        D_00201F80->flags = 1;
        D_00201F80->fd = sceOpen(path, 0x8001, 0x124);
        if (D_00201C7C != 0) {
            D_00201F80->size = 0x800;
        }
    } else {
        strcpy(path, D_001FB758);
        strcat(path, arg0);
        strcat(path, D_001FB760);
        memset(st, 0, 0x24);
        sceCdSearchFile(st, path);
        D_00201F80->x0 = st[0] << 11;
        D_00201F80->x4 = D_00201F80->x0;
        D_00201F80->x8 = 0;
        D_00201F80->xC = 0;
        D_00201F80->flags = mode | 1;
        D_00201F80->fd = -1;
        D_00201F80->size = 0x800;
    }
    if (arg2 == 0) {
        File_Read_2_0015A470(D_00201F80, D_002F20C0, 0x800, 1);
        f = D_00201F80;
        switch (f->flags) {
        case 0x100:
        case 0x200:
            f->x4 = f->x0;
            break;
        case 0x101:
        case 0x201:
            f->x4 = f->x0;
            break;
        case 0:
            f->x4 = f->x0;
            sceLseek(D_00201F80->fd, f->x4, 0);
            break;
        case 1:
            f->x4 = 0;
            sceLseek(f->fd, f->x4, 0);
            break;
        }
        arg2 = D_002F20C8[0];
        D_00201F80->size = (arg2 << 5) + 0x10;
    }
    File_Read_2_0015A470(D_00201F80, D_002F20C0, (arg2 << 5) + 0x10, 1);
    D_00201F80->size = D_002F20C4[0];
}
#undef D_00201F80
#undef D_002F20C0
#undef D_0030A0D0

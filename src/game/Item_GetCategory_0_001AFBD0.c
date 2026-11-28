#include "common.h"
#include "m2c.h"
typedef struct { char b[0x90]; } E;
typedef struct { s32 a; u32 count; s32 b; s32 c; } Hdr;
extern E *D_002022B0;
s32 Item_GetCategory_0_001AFBD0(s32 arg0);
E* Item_GetData_1_001AFC40(s16 i);
s32 Item_GetTable_1_001AFC90(void);
void Item_LoadTables_0_001AFCA0(s8 *arg0);
s32 Item_LoadTableB_0_001AFFA0(void *a);
s32 Arc_LoadFile_2_00159DD0(s32, void *, void*, void *);

/* Item_GetCategory_0_001AFBD0 */
s32 Item_GetCategory_0_001AFBD0(s32 arg0) {
    if ((arg0 >= 0) && (arg0 < 0x64)) {
        return 0;
    }
    if ((arg0 >= 0x64) && (arg0 < 0x320)) {
        return 1;
    }
    if ((arg0 >= 0x320) && (arg0 < 0x400)) {
        return 2;
    }
    return -1;
}

/* Item_GetData_1_001AFC40 */
E *Item_GetData_1_001AFC40(s16 i)
{
    if (D_002022B0 && i > 0 && i <= 0x3FF)
        return &D_002022B0[i];
    return NULL;
}

/* Item_GetTable_1_001AFC90 */
#define D_002022B0 D_002022B0__as_Item_GetTable_1_001AFC90
extern s32 D_002022B0__as_Item_GetTable_1_001AFC90;

s32 Item_GetTable_1_001AFC90(void) {
    return D_002022B0;
}
#undef D_002022B0

/* Item_LoadTables_0_001AFCA0 */
#define D_002022B0 D_002022B0__as_Item_LoadTables_0_001AFCA0
extern u8 *D_002022B0__as_Item_LoadTables_0_001AFCA0;
#define Arc_LoadFile_2_00159DD0 Arc_LoadFile_2_00159DD0__as_Item_LoadTables_0_001AFCA0
void Arc_LoadFile_2_00159DD0__as_Item_LoadTables_0_001AFCA0(s32, s8 *, void *, u32 *);
#define B(d, s) M2C_FIELD(p, u8 *, d) = M2C_FIELD(e, u8 *, s)
#define H(d, s) M2C_FIELD(p, u16 *, d) = M2C_FIELD(e, u16 *, s)
static inline u8 *lookup(s16 id) { if (D_002022B0 != NULL && id > 0 && id < 0x400) return D_002022B0 + id * 0x90; return NULL; }

void Item_LoadTables_0_001AFCA0(s8 *arg0) {
    u32 sz;
    Hdr **hdr;
    Hdr *t0;
    s8 *e;
    u32 i;
    u8 *p;
    s16 id;

    sz = 0;
    Arc_LoadFile_2_00159DD0(0x0DBC359C, arg0, &hdr, &sz);
    t0 = *hdr;
    e = (s8 *)(t0 + 1);
    for (i = 0; i < t0->count; i++, e += 0x40) {
        p = lookup(M2C_FIELD(e, s16 *, 0));
        if (p != NULL) {
            switch (M2C_FIELD(p, u16 *, 0xA)) {
            case 0:
                break;
            case 1:
                H(4, 2); B(6, 8); B(7, 0x3D);
                B(0x22, 4); B(0x23, 5); B(0x24, 6); B(0x25, 7);
                B(0x26, 0x10); B(0x27, 0x11); B(0x28, 0x12); B(0x29, 0x13); B(0x2A, 0x14); B(0x2B, 0x15);
                H(0x2C, 0x18); H(0x2E, 0x1A); H(0x30, 0x1C); H(0x32, 0x1E);
                H(0x34, 0x20); H(0x36, 0x22); H(0x38, 0x24); H(0x3A, 0x26);
                B(0x3C, 9); B(0x3D, 0xC); B(0x3E, 0xA); B(0x3F, 0xB);
                B(0x44, 0x28); B(0x45, 0x29); B(0x46, 0x2A); B(0x47, 0x2B); B(0x48, 0x2C); B(0x49, 0x2D);
                H(0x4A, 0x30); H(0x4C, 0x32); H(0x4E, 0x34); H(0x50, 0x36); H(0x52, 0x38); H(0x54, 0x3A);
                B(0x56, 0xD); H(0x42, 0xE); B(0x57, 0x3C);
                if (p[0x57] == 0) {
                    p[0x57] = 1;
                }
                break;
            case 2:
                H(4, 2); B(6, 8); B(7, 0x3D);
                B(0x22, 4); B(0x23, 5); B(0x24, 6); B(0x25, 7);
                H(0x26, 0x18); H(0x28, 0x1A);
                B(0x2A, 0x10); B(0x2B, 0x11); B(0x2C, 0x12); B(0x2D, 0x13); B(0x2E, 0x14); B(0x2F, 0x15);
                H(0x30, 0x1C); H(0x32, 0x1E);
                H(0x34, 0x20); H(0x36, 0x22); H(0x38, 0x24); H(0x3A, 0x26);
                B(0x3C, 9); B(0x3D, 0xC); B(0x3E, 0xA); B(0x3F, 0xB);
                break;
            }
        }
    }
}
#undef Arc_LoadFile_2_00159DD0
#undef D_002022B0

/* Item_LoadTableB_0_001AFFA0 */
#define D_002022B0 D_002022B0__as_Item_LoadTableB_0_001AFFA0
extern u8 *D_002022B0__as_Item_LoadTableB_0_001AFFA0;

s32 Item_LoadTableB_0_001AFFA0(void *a) {
    s32 sz;
    u32 **h;
    u32 *p;
    s32 q;
    Arc_LoadFile_2_00159DD0(0x48F91304, a, &h, &sz);
    p = *h;
    switch (p[0]) {
    case 0x4D505449:
        q = (s32)p + 0x10;
        D_002022B0 = (u8 *)(q + 0x10 + ((*(u32 *)(q + 0xC) + 0xF) & ~0xF));
        break;
    }
    return 0;
}
#undef D_002022B0

#include "common.h"
extern char D_001FDA80[];
extern s32 D_002022B4;
extern s32 D_002022C4;
void Map_GetFile_2_001B7050(s32 n, char *name, s32 *size);
s32** Map_AllocAreaBuf_1_001B70E0(s32 n);
s32 sprintf(char *buf, const char *fmt, ...);
char* strcpy(char *dst, const char *src);
s32 File_HashName_3_00159D10(char *name);
s32 Arc_FindByHash_2_0015ABD0(s32 a);
s32 File_GetSectorOrSize_0_0015A300(s32 h);
void File_Close_2_0015AB80(s32 h);
s32** Pool_Alloc_3_001288C0(s32, s32);
void memset(void *, s32, s32);

/* Map_GetFile_2_001B7050 */
void Map_GetFile_2_001B7050(s32 n, char *name, s32 *size)
{
    char buf[0x100];
    s32 h;
    sprintf(buf, D_001FDA80, n);
    if (name)
        strcpy(name, buf);
    if (size) {
        h = Arc_FindByHash_2_0015ABD0(File_HashName_3_00159D10(buf));
        *size = File_GetSectorOrSize_0_0015A300(h);
        File_Close_2_0015AB80(h);
    }
}

/* Map_AllocAreaBuf_1_001B70E0 */
static inline void ld(s32 n, s32 *size)
{
    char buf[0x100];
    s32 h;
    sprintf(buf, D_001FDA80, n);
    if (size) {
        h = Arc_FindByHash_2_0015ABD0(File_HashName_3_00159D10(buf));
        *size = File_GetSectorOrSize_0_0015A300(h);
        File_Close_2_0015AB80(h);
    }
}
s32 **Map_AllocAreaBuf_1_001B70E0(s32 n) {
    s32 size;
    s32 **r;
    s32 *p;
    ld(n, &size);
    D_002022B4 = n;
    r = Pool_Alloc_3_001288C0(D_002022C4, 0x1E0);
    p = *r;
    memset(p, 0, 0x1E0);
    p[9] = (s32)Pool_Alloc_3_001288C0(D_002022C4, size);
    p[0] = n;
    return r;
}

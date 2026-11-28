#include "common.h"
#pragma explicit_zero_data on
const char D_001FD970[0x11] = "chr/c%4.04dm.stm\000";
s32 sprintf(char *buf, const char *fmt, ...);
char *strcpy(char *dst, const char *src);
s32 File_HashName_3_00159D10(char *name);
s32 Arc_FindByHash_2_0015ABD0(s32 a);
s32 File_GetSectorOrSize_0_0015A300(s32 h);
void File_Close_2_0015AB80(s32 h);

void EnemyData_GetFile_2_001A7D00(s32 n, char *name, s32 *size)
{
    char buf[0x100];
    s32 h;
    sprintf(buf, D_001FD970, n);
    if (name)
        strcpy(name, buf);
    if (size) {
        h = Arc_FindByHash_2_0015ABD0(File_HashName_3_00159D10(buf));
        *size = File_GetSectorOrSize_0_0015A300(h);
        File_Close_2_0015AB80(h);
    }
}

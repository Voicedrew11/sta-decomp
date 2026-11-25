#include "common.h"
void func_00182050(s32);                     /* extern */
void func_0018B0C0();                            /* extern */
void func_00199170(s32 *);                       /* extern */
void func_0019A7E0(s32 *);                       /* extern */
void func_0019DF80(s32 *);                       /* extern */
void func_0019E8A0(s32 *);                       /* extern */
extern s32 D_004A0B10[];
extern s32 D_004A0B14[];
extern s32 D_004A0B18[];
extern s32 D_004A0B1C[];
extern s32 D_004A0B20[];
extern s8 D_004A0B28[];
extern s8 D_004A0B29[];
extern s8 D_004A0B2C[];
extern s8 D_004A0B2E[];
extern s8 D_004A0B2F[];
extern s32 D_004A0B34[];

void func_0018A350(s8 arg0) {
    (*D_004A0B28) = arg0;
    (*D_004A0B29) = 0;
    (*D_004A0B20) = 0x1F;
    (*D_004A0B2E) = 0x7F;
    (*D_004A0B2F) = 0;
    (*D_004A0B2C) = 0;
    (*D_004A0B34) = 0;
    func_00182050(0x80);
    func_0019A7E0(D_004A0B20);
    func_0019E8A0(D_004A0B20);
    func_0019DF80(D_004A0B20);
    func_00199170(D_004A0B20);
    func_0018B0C0();
    (*D_004A0B10) = 0;
    (*D_004A0B14) = 0;
    (*D_004A0B18) = 0;
    (*D_004A0B1C) = 0;
}

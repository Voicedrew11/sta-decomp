#include "common.h"
void DIntr();                                    /* extern */
void DeleteSema(s32);                            /* extern */
void DeleteThread(s32);                          /* extern */
void DisableDmac(s32);                       /* extern */
void EIntr(s32, s32);                            /* extern */
void RemoveDmacHandler(s32, s32);            /* extern */
void RemoveIntcHandler(s32, s32);            /* extern */
void TerminateThread(s32);                       /* extern */
void func_00109C08(s32 *);                   /* extern */
void func_0010C500(s32);                     /* extern */
s32 func_00112A60(s32);                             /* extern */
void func_00116360(s32, s32, s32, s32); /* extern */
void printf(s32 *, s32 *, s32);      /* extern */
s32 sceCdStStop();                                  /* extern */
void sceClose(s32);                              /* extern */
extern s32 D_00201920[];
extern s32 D_00201940[];
extern s32 D_004BDF24[];
extern s32 D_004BDF38[];
extern s32 D_004BDF40[];
extern s32 D_004BDFC8[];
extern s32 D_004BDFF0[];
extern s32 D_004BDFF4[];
extern s32 D_004BE040[];
extern s32 D_004BE044[];
extern s32 D_004BE04C[];
extern s32 D_004BE078[];
extern s32 D_004BE07C[];

void func_001EC3E0(void) {
    s32 temp_4;
    s32 temp_5;
    s32 var_16;

    TerminateThread((*D_004BE040));
    DeleteThread((*D_004BE040));
    TerminateThread((*D_004BE044));
    DeleteThread((*D_004BE044));
    DisableDmac(2);
    RemoveDmacHandler(2, (*D_004BDFF0));
    func_0010C500(2);
    RemoveIntcHandler(2, (*D_004BDFF4));
    DIntr();
    temp_5 = *(s32 *)0x1000F520;
    temp_4 = temp_5 | 0x10000;
    *(s32 *)0x1000F590 = temp_4;
    *(s32 *)0x1000B400 = 5;
    *(s32 *)0x1000F590 = (s32) (*(s32 *)0x1000F520 & 0xFFFEFFFF);
    EIntr(temp_4, temp_5);
    *(s32 *)0x1000B420 = 0;
    *(s32 *)0x1000B410 = 0;
    *(s32 *)0x1000B430 = 0;
    DeleteSema((*D_004BDFC8));
    func_00109C08(D_004BDF40);
    if (func_00112A60((*D_004BDF24)) < 0) {
        printf(D_00201920, D_00201940, 0x407);
    }
    if (func_00112A60((*D_004BDF38)) < 0) {
        printf(D_00201920, D_00201940, 0x409);
    }
    var_16 = 0;
    do {
        func_00116360(1, 0x8010, var_16 | 0x980, 0);
        func_00116360(1, 0x8010, var_16 | 0xA80, 0);
        var_16 += 1;
    } while (var_16 < 2);
    if ((*D_004BE04C) != 0) {
        do {

        } while (!sceCdStStop() != 0);
        if (func_00112A60((*D_004BE078)) < 0) {
            printf(D_00201920, D_00201940, 0xF6F);
        }
    } else {
        sceClose((*D_004BE07C));
    }
}


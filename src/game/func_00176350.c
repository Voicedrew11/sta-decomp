#include "m2c.h"
typedef struct N { s32 x0; struct N *next; } N;
typedef struct { N *head; s32 x4; } B;
extern u8 D_00438A30[];
extern B D_00438A70[];
void func_001549D0(void);
void func_00175CD0(N *);

void func_00176350(void) {
    u32 i;
    u32 j;
    N *p;

    func_001549D0();
    for (i = 0; i < 0x33; i++) {
        if (D_00438A30[i] != 0) {
            for (j = i * 0x40; j < i * 0x40 + 0x40; j++) {
                p = D_00438A70[j].head;
                while (p != NULL) {
                    func_00175CD0(p);
                    p = p->next;
                }
            }
        }
    }
}

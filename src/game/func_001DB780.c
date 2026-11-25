#include "common.h"
extern s16 D_004BAA34[];
extern u16 D_004BAA36[];

void func_001DB780(void) {
    if ((*D_004BAA36) != 0) {
        func_001D85D0(4, 1, 0x600);
    }
    (*D_004BAA34) = 0;
    func_001D84F0(4, 1, 0xC00, 0);
    if ((*D_004BAA36) != 0) {
        func_001D85D0(4, 1, 0x500);
    }
}

#include "common.h"
typedef struct { char pad[8]; s32 n; char p2[8]; unsigned char f : 2; } B;
typedef struct { char pad[8]; u32 n; char p2[8]; s32 count; } A;
void func_00128580(A *a, B *b) { a->n = b->n + a->n; b->f = 1; a->count++; }

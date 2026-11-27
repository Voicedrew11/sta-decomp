/* Bitfield setter on an object's flag byte at 0x5A1. */

typedef struct {
    char pad[0x5A1];
    unsigned char : 5;
    unsigned char f : 1;
} Obj;

void Enemy_Set5A1b5_1_0013EE90(Obj *o, int v)
{
    o->f = v;
}

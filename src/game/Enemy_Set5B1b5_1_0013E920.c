/* Bitfield setter on an object's flag byte at 0x5B1. */

typedef struct {
    char pad[0x5B1];
    unsigned char : 5;
    unsigned char f : 1;
} Obj;

void Enemy_Set5B1b5_1_0013E920(Obj *o, int v)
{
    o->f = v;
}

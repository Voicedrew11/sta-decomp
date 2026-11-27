/* Bitfield setter on an object's flag byte at 0x5B1. */

typedef struct {
    char pad[0x5B1];
    unsigned char : 1;
    unsigned char f : 1;
} Obj;

void Enemy_Set5B1b1_1_0013EA50(Obj *o, int v)
{
    o->f = v;
}

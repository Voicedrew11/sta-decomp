/* Bitfield setter on an object's flag byte at 0x5B0. */

typedef struct {
    char pad[0x5B0];
    unsigned char : 2;
    unsigned char f : 1;
} Obj;

void Enemy_Set5B0b2_1_0013EBF0(Obj *o, int v)
{
    o->f = v;
}

/* Bitfield setter on an object's flag byte at 0x5B0. */

typedef struct {
    char pad[0x5B0];
    unsigned char : 6;
    unsigned char f : 1;
} Obj;

void Enemy_Set5B0b6_1_0013EB70(Obj *o, int v)
{
    o->f = v;
}

/* Bitfield setter on an object's flag byte at 0x5B0. */

typedef struct {
    char pad[0x5B0];
    unsigned char : 7;
    unsigned char f : 1;
} Obj;

void Enemy_Set5B0b7_1_0013EB40(Obj *o, int v)
{
    o->f = v;
}

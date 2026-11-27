/* Bitfield setter on an object's flag byte at 0x5B2. */

typedef struct {
    char pad[0x5B2];
    unsigned char : 4;
    unsigned char f : 1;
} Obj;

void Enemy_Set5B2b4_1_0013E790(Obj *o, int v)
{
    o->f = v;
}

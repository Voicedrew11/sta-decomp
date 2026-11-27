/* Bitfield setter on an object's flag byte at 0x5B6. */

typedef struct {
    char pad[0x5B6];
    unsigned char : 3;
    unsigned char f : 1;
} Obj;

void Enemy_Set5B6b3_1_0013EAB0(Obj *o, int v)
{
    o->f = v;
}

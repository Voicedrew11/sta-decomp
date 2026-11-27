/* Bitfield setter on an object's flag byte at 0x5B6. */

typedef struct {
    char pad[0x5B6];
    unsigned char : 1;
    unsigned char f : 1;
} Obj;

void Enemy_Set5B6b1_1_0013E6F0(Obj *o, int v)
{
    o->f = v;
}

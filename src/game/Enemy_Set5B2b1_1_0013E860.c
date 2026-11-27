/* Bitfield setter on an object's flag byte at 0x5B2. */

typedef struct {
    char pad[0x5B2];
    unsigned char : 1;
    unsigned char f : 1;
} Obj;

void Enemy_Set5B2b1_1_0013E860(Obj *o, int v)
{
    o->f = v;
}

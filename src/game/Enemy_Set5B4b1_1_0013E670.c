/* Bitfield setter on an object's flag byte at 0x5B4. */

typedef struct {
    char pad[0x5B4];
    unsigned char : 1;
    unsigned char f : 1;
} Obj;

void Enemy_Set5B4b1_1_0013E670(Obj *o, int v)
{
    o->f = v;
}

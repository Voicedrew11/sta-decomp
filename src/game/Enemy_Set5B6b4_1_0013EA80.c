/* Bitfield setter on an object's flag byte at 0x5B6. */

typedef struct {
    char pad[0x5B6];
    unsigned char : 4;
    unsigned char f : 1;
} Obj;

void Enemy_Set5B6b4_1_0013EA80(Obj *o, int v)
{
    o->f = v;
}

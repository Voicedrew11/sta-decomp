/* Bitfield setter on an object's flag byte at 0x5B0. */

typedef struct {
    char pad[0x5B0];
    unsigned char f : 1;
} Obj;

void func_0013EC30(Obj *o, int v)
{
    o->f = v;
}

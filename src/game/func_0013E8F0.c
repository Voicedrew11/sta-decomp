/* Bitfield setter on an object's flag byte at 0x5B1. */

typedef struct {
    char pad[0x5B1];
    unsigned char : 6;
    unsigned char f : 1;
} Obj;

void func_0013E8F0(Obj *o, int v)
{
    o->f = v;
}

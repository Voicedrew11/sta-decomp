/* Bitfield setter on an object's flag byte at 0x5B2. */

typedef struct {
    char pad[0x5B2];
    unsigned char : 6;
    unsigned char f : 2;
} Obj;

void func_0013E730(Obj *o, int v)
{
    o->f = v;
}

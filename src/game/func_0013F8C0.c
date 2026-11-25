/* Bitfield setter on an object's flag byte at 0x5B6. */

typedef struct {
    char pad[0x5B6];
    unsigned char : 5;
    unsigned char f : 1;
} Obj;

void func_0013F8C0(Obj *o, int v)
{
    o->f = v;
}

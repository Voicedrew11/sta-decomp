/* Bitfield setter on an object's flag byte at 0x5B4. */

typedef struct {
    char pad[0x5B4];
    unsigned char : 6;
    unsigned char f : 1;
} Obj;

void func_0013E490(Obj *o, int v)
{
    o->f = v;
}

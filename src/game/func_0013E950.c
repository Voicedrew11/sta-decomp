/* Bitfield setter on an object's flag byte at 0x5B5. */

typedef struct {
    char pad[0x5B5];
    unsigned char : 7;
    unsigned char f : 1;
} Obj;

void func_0013E950(Obj *o, int v)
{
    o->f = v;
}

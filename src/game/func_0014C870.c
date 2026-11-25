/* Bitfield setter on an object's flag byte at 0x114. */

typedef struct {
    char pad[0x114];
    unsigned char : 3;
    unsigned char f : 1;
} Obj;

void func_0014C870(Obj *o)
{
    o->f = 1;
}

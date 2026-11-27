/* Bitfield setter on an object's flag byte at 0x188. */

typedef struct {
    char pad[0x188];
    unsigned char : 3;
    unsigned char f : 1;
} Obj;

void Sfx_RequestStop_1_00167240(Obj *o)
{
    o->f = 1;
}

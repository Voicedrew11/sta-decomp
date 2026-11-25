/* Bitfield getters and setter on an object's flag bytes at 0x5B1 and 0x5B4. */

typedef struct {
    char pad[0x5B1];
    unsigned char a0 : 1, a1 : 1, a2 : 1, a3 : 1;
    char pad2[2];
    unsigned char b0 : 1, b1 : 1, b2 : 1, b3 : 1;
} Obj;

void func_0013E620(Obj *o, int v)
{
    o->b3 = v;
}

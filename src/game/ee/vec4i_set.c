typedef unsigned int u32;
typedef unsigned short u16;

/* Append four words to a packet. */
u32 *Vec4i_Set_1_001E52B8(u32 *p, u32 a, u32 b, u32 c, u32 d)
{
    p[0] = a;
    p[1] = b;
    p[2] = c;
    p[3] = d;
    return p + 4;
}

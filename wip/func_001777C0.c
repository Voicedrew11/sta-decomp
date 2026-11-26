#include "m2c.h"
typedef struct {
    u64 tbp0 : 14;
    u64 tbw : 6;
    u64 psm : 6;
    u64 tw : 4;
    u64 th : 4;
    u64 tcc : 1;
    u64 tfx : 2;
    u64 cbp : 14;
    u64 cpsm : 4;
    u64 csm : 1;
    u64 csa : 5;
    u64 cld : 3;
} Tex0;
typedef struct {
    Tex0 tex0;
    u64 d8;
    u32 f10;
    u16 f14;
    u8 pad16[6];
    s16 prev;
    s16 next;
    u16 pad20;
    u16 f22;
    u8 pad24[4];
    u8 kind : 3;
    u8 tb : 5;
    u8 pad29;
    u16 f2A;
    u16 pad2C;
    u16 f2E;
} Tex;
typedef struct {
    s16 prev, next, fnext, fprev;
    u16 off, size;
    void *owner;
} Blk;
extern Blk D_0047F0C0[];
extern Tex D_004800C0[];
extern volatile s16 D_004830C8[];
#define D_004830C8 D_004830C8[0]
extern s16 D_004830CA[];
#define D_004830CA D_004830CA[0]
extern s16 D_004830CC[];
#define D_004830CC D_004830CC[0]
extern s16 D_004830CE[];
#define D_004830CE D_004830CE[0]
extern s32 D_00202018;
u16 func_00176BF0(Tex *, u16);

#define F(fld, o) (*(__typeof__(D_004800C0[0].fld) *)((u8 *)&D_004800C0[0].fld + (o)))
void func_001777C0(u16 a0, u64 *a1, u64 *a2) {

    s32 n;
    s32 off;
    s16 h;
    u16 r;
    Tex *p;

    a0 = (a0 + 0x1F) & ~0x1F;
    n = D_004830C8;
    off = n * sizeof(Tex);
    D_004830CA--;
    if (n == F(prev, off)) {
        D_004830C8 = -1;
    } else {
        D_004800C0[F(prev, off)].next = F(next, off);
        D_004800C0[F(next, off)].prev = F(prev, off);
        if (D_004830C8 == n) D_004830C8 = F(prev, off);
    }
    D_004830CE++;
    h = D_004830CC;
    if (h == -1) {
        D_004830CC = n;
        F(prev, off) = n;
        D_004800C0[n].next = n;
    } else {
        D_004800C0[n].prev = h;
        D_004800C0[n].next = D_004800C0[h].next;
        D_004800C0[D_004800C0[n].prev].next = n;
        D_004800C0[D_004800C0[n].next].prev = n;
        D_004830CC = n;
    }
    D_00202018 = 0;
    p = &D_004800C0[n];
    p->kind = 3;
    D_004800C0[n].f2A = a0 << 4;
    D_004800C0[n].f2E = 0;
    D_004800C0[n].f14 = a0 << 4;
    r = func_00176BF0(p, (u32)(D_004800C0[n].f2A + D_004800C0[n].f2E + 15) >> 4);
    D_004800C0[n].f22 = r;
    D_004800C0[n].f10 = D_0047F0C0[r].off;
    if (a1) p->tex0 = *(Tex0 *)a1;
    if (a2) F(d8, off) = *a2;
    D_004800C0[n].tex0.tbp0 = D_004800C0[n].f10;
    D_004800C0[n].tex0.cbp = D_004800C0[n].f10;
    D_00202018 = 0;
}

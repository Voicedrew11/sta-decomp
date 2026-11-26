#include "m2c.h"
typedef struct { u16 a, b, c, n; u8 pad[0x38]; s8 data[1]; } Hd;
typedef struct { u8 pad[0xC]; u8 a:6; u8 en:1; u8 b:1; } Fl;
typedef struct { u8 pad[0x124]; s32 h[8]; } Obj;
typedef struct { u8 pad[0x18]; Obj *objs; s8 *ents; } O;
void func_00102A70(void *, s8 *);
void func_00173FD0(void *, s8 *, s8 *, s8 *);
void func_001027E0(void *, void *, void *);
void func_001677C0(s32, void *);
extern s32 D_00201F2C;

void func_001A83E0(s8 *arg0) {
    f32 mtx[16] __attribute__((aligned(16)));
    f32 tmp[16] __attribute__((aligned(16)));
    s8 *v;
    s32 i;
    s8 *e;
    s32 off;
    s32 off4;
    s8 *base;
    O *o;
    Hd *h;
    if (arg0 != NULL) {
        base = M2C_FIELD(arg0, s8 **, 0x518);
        o = (O *)(base + 0x180);
        if (M2C_FIELD(base, Fl **, 0x19C)->en) {
            h = *M2C_FIELD(base, Hd ***, 0xB0);
            i = 0;
            off = 0;
            off4 = 0;
            v = (s8 *)((s32)h->data + D_00201F2C * (h->n * 0x140 + 0x200));
            do {
                s8 *t = o->ents + off;
                e = t + 0x2B0;
                if (M2C_FIELD(t, u16 *, 0x2E0) != 0) {
                    func_00102A70(mtx, v + (M2C_FIELD(e, u8 *, 0x32) + 1) * 0x140 + 0xC0);
                    func_00173FD0(tmp, e, e + 0x10, e + 0x20);
                    func_001027E0(mtx, mtx, tmp);
                    func_001677C0(M2C_FIELD((s8 *)o->objs + off4, s32 *, 0x124), mtx);
                }
                i++;
                off += 0x40;
                off4 += 4;
            } while (i < 8);
        }
    }
}

#include "common.h"
typedef struct { u8 pad[0x23]; u8 on; u8 pad2[0xC]; } E;
typedef struct {
    f32 f[6];
    u8 pad[0xB0 - 0x18];
    E e[2][32];
    u8 padCB0[4];
    u16 n[2];
} S;
extern S D_0030C420[];
extern Vec D_0030C3E0[];
typedef struct { u8 b[4]; u16 h; u8 c; } C;
extern C D_0030C48C[];
void func_00102A70(Vec *, void *);
f32 func_0015BDE0(E *);
void func_00159340(u8, u8, u8, u8, u16, u8);

void func_0015C0C0(void *arg0) {
    s32 i;
    s32 j;
    s32 cnt;
    f32 sum;
    f32 inv;

    cnt = 0;
    sum = 0.0f;
    D_0030C420[0].f[0] = 0.0f;
    D_0030C420[0].f[1] = 0.0f;
    D_0030C420[0].f[2] = 0.0f;
    D_0030C420[0].f[3] = 0.0f;
    D_0030C420[0].f[4] = 0.0f;
    D_0030C420[0].f[5] = 0.0f;
    func_00102A70(D_0030C3E0, arg0);
    for (i = 0; i < 2; i++) {
        if (D_0030C420[0].n[i]) {
            for (j = 0; j < 32; j++) {
                if (D_0030C420[0].e[i][j].on) {
                    sum += func_0015BDE0(&D_0030C420[0].e[i][j]);
                    cnt++;
                }
            }
        }
    }
    if (cnt) {
        inv = 1.0f / sum;
        D_0030C48C[0].b[0] = D_0030C420[0].f[0] * inv;
        D_0030C48C[0].b[1] = D_0030C420[0].f[1] * inv;
        D_0030C48C[0].b[2] = D_0030C420[0].f[2] * inv;
        D_0030C48C[0].b[3] = D_0030C420[0].f[3] * inv;
        D_0030C48C[0].h = D_0030C420[0].f[4] * inv;
        D_0030C48C[0].c = D_0030C420[0].f[5] * inv;
    } else {
        inv = 1.0f;
        D_0030C48C[0].b[0] = D_0030C420[0].f[0] * inv;
        D_0030C48C[0].b[1] = D_0030C420[0].f[1] * inv;
        D_0030C48C[0].b[2] = D_0030C420[0].f[2] * inv;
        D_0030C48C[0].b[3] = D_0030C420[0].f[3] * inv;
        D_0030C48C[0].h = D_0030C420[0].f[4] * inv;
        D_0030C48C[0].c = D_0030C420[0].f[5] * inv;
    }
    func_00159340(D_0030C48C[0].b[0], D_0030C48C[0].b[1], D_0030C48C[0].b[2], D_0030C48C[0].b[3], D_0030C48C[0].h, D_0030C48C[0].c);
}

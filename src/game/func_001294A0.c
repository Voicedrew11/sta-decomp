typedef float f32;
typedef f32 Mtx[4][4];
void sceVu0UnitMatrix(Mtx);
void sceVu0MulMatrix(Mtx, Mtx, Mtx);

void func_001294A0(Mtx m0, Mtx m1, Mtx m2, f32 a, f32 b, f32 c, f32 d, f32 e, f32 f, f32 g, f32 h, f32 i, f32 j, f32 k)
{
    Mtx t;
    f32 sx = j * f / a;
    f32 sy = j * g / a;
    f32 jk;

    sceVu0UnitMatrix(m0);
    m0[0][0] = a;
    m0[1][1] = a;
    m0[2][2] = 0.0f;
    m0[3][3] = 0.0f;
    m0[3][2] = 1.0f;
    m0[2][3] = 1.0f;
    sceVu0UnitMatrix(t);
    jk = k * j;
    t[2][2] = jk * (-h + i) / (-j + k);
    t[3][2] = (-i * j + h * k) / (-j + k);
    t[0][0] = b;
    t[1][1] = c;
    t[3][0] = d;
    t[3][1] = e;
    sceVu0MulMatrix(m0, t, m0);
    sceVu0UnitMatrix(m1);
    m1[0][0] = 2.0f * j / (sx + sx);
    m1[1][1] = 2.0f * j / (sy + sy);
    m1[2][2] = (k + j) / (k - j);
    m1[3][2] = -2.0f * jk / (k - j);
    m1[2][3] = 1.0f;
    m1[3][3] = 0.0f;
    sceVu0UnitMatrix(m2);
    m2[0][0] = sx * (a * b) / j;
    m2[1][1] = sy * (a * c) / j;
    m2[2][2] = (-i + h) / 2.0f;
    m2[3][2] = (i + h) / 2.0f;
    m2[3][0] = d;
    m2[3][1] = e;
    m2[3][3] = 1.0f;
}

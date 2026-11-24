float func_0011DA18(float);
float func_0011D778(float);

void func_0015E500(char * a0, char * a1, float f0) {
    float t1;
    float t2;
    t1 = func_0011DA18((0.5f * f0));
    *(float *)a0 = (*(float *)a1 * t1);
    *(float *)(a0 + 0x4) = (*(float *)(a1 + 0x4) * t1);
    *(float *)(a0 + 0x8) = (*(float *)(a1 + 0x8) * t1);
    t2 = func_0011D778((0.5f * f0));
    *(float *)(a0 + 0xC) = t2;
}

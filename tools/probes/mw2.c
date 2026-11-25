/* Compiler probe (see mw.c): kept apart because it calls func_0013EA40,
 * which mw.c defines. */

typedef struct { char pad[0x154]; void *p; } Ctx;
extern Ctx *D_00201FA8;
int func_0013EA40(void *);
void func_0018B0C0(void);
void func_0013EA20(void *, int);

void func_00144F00(unsigned char *a)
{
    void *p = D_00201FA8->p;
    int v = a[8];
    if (!(unsigned char)func_0013EA40(p) && v)
        func_0018B0C0();
    func_0013EA20(p, v);
}

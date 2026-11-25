#include "common.h"

void func_001ACEB0(void (*f)(void));
void func_001AD030(void);
void func_001ACFE0(void);
void func_0016B280(void);

void func_001AD080(void)
{
    func_001ACEB0(func_001AD030);
    func_001ACEB0(func_001ACFE0);
    func_0016B280();
}

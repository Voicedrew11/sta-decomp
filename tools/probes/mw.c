/* Compiler probe: game functions written in C that CodeWarrior 3.0b38/b50/b52
 * at -O4,p compiles to the retail bytes. Used by tools/probe_compiler.py to
 * tell the mwccps2 builds and flag sets apart; not part of the build. The
 * types and names are guesses. */

void *memset(void *, int, unsigned int);

typedef struct {
    char pad[0x5B1];
    unsigned char a0 : 1, a1 : 1, a2 : 1, a3 : 1;
    char pad2[2];
    unsigned char b0 : 1, b1 : 1, b2 : 1, b3 : 1;
} Obj;

/* bitfield getters and setter: 2.x builds differ from here on (13DCE0) */
int func_0013E690(Obj *o) { return o->b1; }
int func_0013EA40(Obj *o) { return o->a2; }
void func_0013E620(Obj *o, int v) { o->b3 = v; }

typedef struct { char pad[0x4A8]; int **q; } Hold;
/* 2.3.3 and 2.4 do not fill the b's delay slot the same way */
int *func_0013DCE0(Hold *h)
{
    if (h->q)
        return (int *)((char *)*h->q + 0x10);
    return 0;
}

extern int D_00202390;
extern long long D_00202398, D_002023A0, D_00202388, D_00202380;
/* 3.0.1b44 and later schedule the loads and stores differently */
void func_001DF960(void)
{
    if (D_00202390) {
        D_00202388 = D_00202398;
        D_00202380 = D_002023A0;
        D_00202390 = 0;
    }
}

typedef struct { int id; char pad[0x30C]; } Item;
typedef struct { int a, b; Item item[4]; } Mgr;
extern Mgr D_00437DC0;
/* the unrolled loop matches only at -O4,p (not -O4,s or -O3) */
void func_00175C80(void)
{
    int i;
    memset(&D_00437DC0, 0, sizeof(Mgr));
    for (i = 3; i >= 0; i--)
        D_00437DC0.item[i].id = -1;
}

typedef struct { char pad[0x10]; int id; } S;
int *func_00165130(S *, int);
int func_001B17E0(int *);
/* only the 2003 3.0 betas (b38, b50, b52) */
void func_0017DC70(S *s)
{
    int *r = func_00165130(s, 0);
    int id = s->id;
    int t = -1;
    *r = func_001B17E0(&t);
    if (t != id)
        *r = -1;
}

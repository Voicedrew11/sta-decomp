/* STA: the soft-double "greater than" the game's CodeWarrior code calls for
 * a double compare, linked right after crt0 (not in kfiv-decomp; the name is
 * derived, after gcc's soft-float comparison helpers).  dpcmp is libgcc's
 * three-way compare. */
int dpcmp(double a, double b);

int __gtdf2(double a, double b)
{
    return dpcmp(a, b) > 0;
}

/* One 0x60-byte text colour entry.
 * cf. KFIV's Message_GetColor (kfiv-decomp src/game/ui/message.c). */

typedef struct { char data[0x60]; } TextColour;
extern TextColour D_0030D9A0[];

TextColour *func_0015D580(int colour)
{
    return &D_0030D9A0[colour];
}

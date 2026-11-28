/* The frame count of a model's motion `index`.
 * cf. KFIV's Motion_FrameCount (kfiv-decomp src/game/entity/entity_ai.c). */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct { char pad[0x20]; u16 frames; } Motion;
typedef struct { char pad[0x4B4]; Motion *motions[1]; } Model;

u16 Model_GetMotionFrames_2_0013F5A0(Model *model, u8 index)
{
    return model->motions[index]->frames;
}

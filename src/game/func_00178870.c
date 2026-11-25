/* Build a perspective projection matrix.
 * The same function as KFIV's Display_BuildProjection (kfiv-decomp
 * src/game/core/display.c); here the scale is divided by 1024 rather than
 * multiplied by 1/1024. */

typedef float f32;
void sceVu0UnitMatrix(f32 (*matrix)[4]);

void func_00178870(f32 (*matrix)[4], f32 screen_scale, f32 near_plane, f32 far_plane)
{
    sceVu0UnitMatrix(matrix);
    matrix[1][1] = matrix[0][0] = screen_scale / 1024.0f;
    matrix[2][2] = (far_plane + near_plane) / (far_plane - near_plane);
    matrix[3][2] = far_plane * near_plane * -2.0f / (far_plane - near_plane);
    matrix[2][3] = 1.0f;
    matrix[3][3] = 0.0f;
}

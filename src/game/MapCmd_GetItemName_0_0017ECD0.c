char *Script_GetArgPtr_2_00165130(char *, int);
int Msg_GetText_2_00195B10(int);
int Msg_ShowWrap_1_0018AC90(int, int);

void MapCmd_GetItemName_0_0017ECD0(char *a0) {
    char *p = Script_GetArgPtr_2_00165130(a0, 1);
    int q = Msg_GetText_2_00195B10(*(int *)(a0 + 8));
    int v = 3;
    if (q) {
        v = Msg_ShowWrap_1_0018AC90(q, 0);
    }
    *p = v;
}

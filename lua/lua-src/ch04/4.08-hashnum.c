#define numints cast_int(sizeof(lua_Number)/sizeof(int))

/* Lua 5.1 之前 */
static Node *hashnum(const Table *t, lua_Number n)
{
    unsigned int a[numints];
    int i;
    if (luai_numeq(n, 0)) return gnode(t, 0);
    memcpy(a, &n, sizeof(a));
    for (i = 1; i < numints; i++) a[0] += a[i];
    return hashmod(t, a[0]);
}

static Node *hashnum(const Table *t, lua_Number n)
{
    int i;
    luai_hashnum(i, n);

    if (i < 0)
    {
        if (cast(unsigned int, i) == 0u - i) i = 0;
        i = -i;
    }
    return hasmod(t, i);
}

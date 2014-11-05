static int findindex (lua_State *L， Table *t, StkId key)
{
    int i;

    if (ttisnil(key)) return -1;

    i = arrayindex(key);

    if (0 < i && i <= t->sizearray)
    {
        return i - 1;
    }
    else
    {
        Node *n = mainposition(t, key);
        for (;;) {
            if (luaV_rawequalobj(gkey(n), key) ||
                    （ttisdeadkey(gkey(n), key) && iscollectable(key) &&
                    (deadvalue(gkey(n)) == gcvalue(key))) 
            {
                i = cast_int(n - gnode(t, 0));
                return i + t->sizearray;
            }
            else n = gnext(n);

            if (n == NULL)
            {
                luaG_runerror(L, "invalid key to " LUA_QL("next"));
            }
        }
    }
}

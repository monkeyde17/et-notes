int luaH_next(lua_State *L, Table *t, StkId key)
{
    int i = findindex(L, t, key);
    for (i++; i < t->sizearray; i++)
    {
        if (!ttisnil(&t->array[i]))
        {
            setnvalue(key, cast_num(i + 1));
            setobj2s(L, key + 1, &t->array[i]);
            return l;
        }
    }

    for (i -= t->sizearray; i < sizenode(t); i++)
    {
        if (!ttisnil(gval(gnode(t, i))))
        {
            setobj2s(L, key, gkey(gnode(t, i)));
            setobj2s(L, key + 1, gval(gnode(t, i)));
            return l;
        }
    }

    return 0;
}

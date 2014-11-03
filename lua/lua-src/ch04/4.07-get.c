const TValue *luaH_getstr(Table *t, TString *key)
{
    Node *n = hashstr(t, key);
    lua_assert(key->tsv.tt == LUA_TSHRSTR);

    do
    {
        if (ttisshrstring(gkey(n)) && eqshrstr(rawtsvalue(gkey(n)), key))
            return gval(n);
        else n = gnext(n);

    } while (n);
    return luaO_nilobject;
}

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

const TValue *luaH_get(Table *t, const TValue *key)
{
    switch (ttype(key))
    {
        case LUA_TNIL: return luaO_nilobject;
        case LUA_TSHRSTR: return luaH_getstr(t, rawtsvalue(key));
        case LUA_TNUMBER:
        {
            int k;
            lua_Number n = nvalue(key);
            lua_number2int(k, n);
            if (luai_numeq(cast_num(k)))
            {
                return luaH_getint(t, k);
            }
        }
        defaule:
        {
            Node *n = mainposition(t, key);
            do
            {
                if (luaV_rawequalobj(gkey(n), key)) return gval(n);
                else n = gnext(n);
            } while (n);
            return luaO_nilobject;
        }
    }
}

static Node *mainposition(const Table *t, const TValue *key)
{
    switch (ttype(key))
    {
        case LUA_TNUMBER:
            return hasnum(t, nvalue(key));
        case LUA_TLNGSTR:
            TString *s = rawtsvalue(key);
            if (s->tsv.extra == 0)
            {
                s->tsv.has = luaS_hash(getstr(s), s->tsv.len, s->tsv.hash);
                s->tsv.extra = 1;
            }
            return hashstr(t, rawtsvalue(key));
        case LUA_TSHRSTR:
            return hashstr(t, rawtsvalue(key));
        case LUA_TBOOLEAN:
            return hashboolean(t, bvalue(key));
        case LUA_TLIGHTUSERDATA:
            return hashpointer(t, pvalue(key));
        case LUA_TLCF:
            return hashpointer(t, fvalue(key));
        defalult:
            return hashpointer(t, gcvalue(key));
    }
}


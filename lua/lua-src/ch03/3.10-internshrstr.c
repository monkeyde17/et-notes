static TString *internshrstr(lua_State *L, const char *str, size_t l)
{
    GCObject *o;
    global_State *g = G(L);
    unsigned int h = luaS_hash(str, l, g->seed);
    for (o = g->strt.hash[lmod(h, g->strt.size)]; o != NULL; o = gch(o)->next)
    {
        TString *ts = rawgco2ts(o);
        if (h == ts->tsv.hash && ts->tsv.len == l && (memcmp(str, getstr(ts), l * sizeof(char)) == 0))
        {
            if (isdead(G(L), o)) changewhite(o);
            return ts;
        }
    }

    return newshrstr(L, str, l, h);
}

void luaS_resize(lua_State *L, int newsize)
{
    int i;
    stringtable *tb = &G(L)->strt;
    luaC_runtilstate(L, ~bitmask(GCSsweepstring));
    if (newsize > tb->size)
    {
        luaM_reallocvector(L, tb->hash, tb->size, newsize, GCObject *);
        for (i = tb->size; i < newsize; i++)
            tb->hash[i] = NULL;
    }

    for (i = 0; i < tb->size; i++)
    {
        GCObject *p = tb->hash[i];
        tb->hash[i] = NULL;
        while (p)
        {
            GCObject *next = gch(p)->next;
            unsigned int h = lmod(gco2ts(p)->hash, newsize);
            gch(p)->next = tb->hash[h];
            tb->hash[h] = p;
            resetoldbit(p);
            p = next;
        }
    }

    if (newsize < tb->size)
    {
        lua_assert(tb->hash[newsize] == NULL && tb->hash[tb->size - 1] == NULL);
        luaM_rellocverctor(L, tb->hash, tb->size, newsize, GCObject *);
    }

    tb->size = newsize;
}

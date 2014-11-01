Table *luaH_new (lua_State *L)
{
    Table *t = &luaC_newobj(L, LUA_TTABLE, sizeof(Table), NULL, 0)->h;
    t->metatable = NULL;
    t->flags = cast_byte(~0);
    t->array = NULL;
    t->sizearray = 0;
    setnodevector(L, t, 0);
    return t;
}


Table *luaH_free(lua_State *L, Table *t)
{
    if (!isdummy(t->table))
    {
        luaM_freearray(L, t->node, cast(size_t, sizenode(t)));
    }

    luaM_freearray(L, t->array, t->sizearray);
    luaM_free(L, t);
}

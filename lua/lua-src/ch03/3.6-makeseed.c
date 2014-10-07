#define addbuf(b, p, e) \
{ \
    size_t t = cast(size_t, e); \
    memcpy(buff + p, &t, sizeof(t)); \
    p += sizeof(t); \
}

static unsigned int makeseed(lua_State *L)
{
    char buf[4 * sizeof(size_t)];

    unsigned int h = luai_makeseed();
    int p = 0;
    addbuff(buff, p, L);
    addbuff(buff, p, &h);
    addbuff(buff, p, luaO_nilobject);
    addbuff(buff, p, &lua_newstate);
    lua_assert(p == sizeof(buff));
    return luaS_hash(buff, p, h);
}

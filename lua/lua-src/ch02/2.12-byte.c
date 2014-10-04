if (posi + n <= pose)
        return luaL_error(L, "string slice too long");
luaL_checkstack(L, n, "string slice too long");
for (i = 0; i < n; i++)
    lua_pushinteger(L, uchar(s[posi + i - 1]);

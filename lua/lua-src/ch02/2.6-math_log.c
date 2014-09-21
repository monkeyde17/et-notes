
static int math_log (lua_State *L)
{
	lua_Number x = luaL_checknumber(L, 1);
	lua_Number res;

	if (lua_isnoneornil(L, 2))
		res = l_tg(log)(x);
	else
	{
		lua_Number base = luaL_checknumber(L, 2);
		if (base == 10.0) res = l_tg(log10)(x);
		else res = l_tg(log)(x) / l_tg(log)(base);
	}

	lua_pushnumber(L, res);

	return 1;
}

#if defined(LUA_COMPAT_LOG10)
static int math_log10(lua_State *L)
{
	lua_pushnumber(L, l_tg(log10)(luaL_checknumber(L, 1)));
	return 1;
}
#endif


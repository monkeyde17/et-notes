/**
 * 该宏体现了lua的订制性
 */
#if !defined(l_tg)
#define l_tg(x) (x)
#endif

static int math_abs(lua_State *L)
{
	lua_pushnumber(L, l_tg(fabs)(luaL_checknumber(L, 1)));
	return 1;
}


static int math_sin(lua_State *L)
{
	lua_pushnumber(L, l_tg(sin)(luaL_checknumber(L, 1)));
	return 1;
}

static int math_sinh(lua_State *L)
{
	lua_pushnumber(L, l_tg(sinh)(luaL_checknumber(L, 1)));
	return 1;
}


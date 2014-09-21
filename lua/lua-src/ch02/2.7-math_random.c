static int math_random(lua_State *L)
{
	lua_Number r = (lua_Number)(rand() % RAND_MAX) / (lua_Number)RAND_MAX;
	switch (lua_gettop(L))
	{
		/* float 0 ~ 1 */
		case 0:
		{
			lua_pushnumber(L, r);
			break;
		}
		/* int 1 ~ u */
		case 1:
		{
			lua_Number u = luaL_checknumber(L, 1);
			luaL_argcheck(L, 1.0 <= u, 1, "interval is empty");
			lua_pushnumber(L, l_tg(floor)(r * u) + 1.0);
			break;
		}
		/* int l ~ u */
		case 2:
		{
			lua_Number l = luaL_checknumber(L, 1);
			lua_Number u = luaL_checknumber(L, 2);
			luaL_argcheck(L, l <= u, 2, "interval is empty");
			lua_pushnumber(L, l_tg(floor)(r * (u - l + 1) + 1));
			break;
		}
		default:
		return luaL_error(L, "wrong number of arguments");
	}

	return 1;
}

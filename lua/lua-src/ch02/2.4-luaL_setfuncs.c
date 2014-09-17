LUALIB_API void luaL_setfuncs(lua_State *L, const luaL_Reg *l, int nup)
{
	luaL_checkversion(L);
	luaL_checkstack(L, nup, "too many upvalues");

	for (; l->name != NULL; l++)
	{
		int i;
		for (i = 0; i < nup; i++)
		{
			lua_pushvalue(L, -nup);
		}
		lua_pushccloure(L, l->func, nup);
		lua_setfield(L, -(nup + 2), l->name);
	}

	lua_pop(L, nup);
}

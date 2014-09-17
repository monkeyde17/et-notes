#define luaL_newlibtable(L, l) \
	lua_createtable(L, 0, sizeof(l) / sizeof((l)[0]) - 1)

#define luaL_newlib(L, l) (luaL_newlibtable(L, l), luaL_setfuncs(L, 1, 0))

LUAMOD_API int luaopen_string (lua_State *L)
{
	luaL_newlib(L, strlib);
	createmetatable(L);
	return 1;
}

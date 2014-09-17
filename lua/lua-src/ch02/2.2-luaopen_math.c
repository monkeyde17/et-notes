LUAMOD_API int luaopen_math(lua_State *L)
{
	luaL_newLib(L, mathlib);
	lua_pushnumber(L, PI);
	lua_setfield(L, -2, "pi");
	lua_pushnumber(L, HUGE_VAL);
	lua_setfield(L, -2, "huge");
	return 1
}

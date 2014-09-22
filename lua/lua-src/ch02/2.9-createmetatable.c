static void createmetatable(lua_State *L)
{
	lua_createtable(L, 0, 1);
	lua_pushliteral(L, "");
	lua_pushvalue(L, -2);
	lua_setmetatable(L, -2);
	lua_pop(L, 1);
	lua_pushvalue(L, -2);
	lua_setfield(L, -2, "__index");
	lua_pop(L, 1);
}

int luaS_eqlngstr (TString *a, TString *b)
{
    size_t len = a->tsv.len;
    lua_assert(a->tsv.tt == LUA_TLNGSTR && b->tsb.tt == LUA_TLNGSTR);
    return (a == b) || /* 先比较地址 */
        ((len == b->tsv.len) && /* 检查长度是否相等 */
         (memcmp(getstr(a), getstr(b), len) == 0)); /* 最后逐个比较字符 */
}

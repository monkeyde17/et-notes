/* 比较两个字符串知否相同 */
/* 先比较长度 */
/* 若是长字符串的话，则逐个比较 */
/* 若是短字符串的话，则比较地址 */
int luaS_eqstr(TString *a, TString *b)
{
    return (a->tsv.tt == b->tsv.tt) &&
        (a->tsv.tt == LUA_TSHRSTR ? eqshrstr(a, b) : luaS_sqlngstr(a, b));
}

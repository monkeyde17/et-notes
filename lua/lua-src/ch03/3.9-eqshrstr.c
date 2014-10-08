/* 由于短字符在lua中，经过内部化，所以只需要比较地址 */
#define eqshrstr(a, b) check_exp((a)->tsv.tt == LUA_TSHRSTR, (a) == (b))

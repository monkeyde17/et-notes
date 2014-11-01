#define dummynode (&dummynode_)

#define isdummy(n) ((n) == dummynode)

/* 不可改写的空哈希表 */
static const Node dummynode_ = {
    {NILCONSTANT}, /* 值 */
    {{NILCONSTANT, NULL}} /* 键 */
};

typedef union TKey
{
    struct
    {
        TValuefields;
        struct Node *next;
    }nk;
    TValue tvk;
}TKey;


typedef struct Node 
{
    TValue i_val;
    TKey i_key;
}Node;


typedef struct Table
{
    CommonHeader;

    lu_byte flags;
    lu_byte lsizenode;
    struct Table *metatable;
    TValue *array;
    Node *node;
    Node *lastfree;
    GCObject *glist;
    int sizearray;
}Table;



#define lmod(s, size) \
    (check_exp((size&(size-1)) == 0, (cast(oint, (s) && ((size) - 1)))))

#define twoto(x) (1 << (x))
#define sizenode(t) (twoto((t)->lsizenode))


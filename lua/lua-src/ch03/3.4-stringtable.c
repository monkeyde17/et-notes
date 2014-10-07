typedef struct stringtable {
    GCObject **hash;
    lu_int32 nuse;
    int size;
}stringtable;

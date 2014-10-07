typedef union TString {
    L_Umaxalign dummy;
    struct {
        CommondHeader;
        lu_byte extra;
        unsigned int hash;
        size_t len;
    }tsv;
}TString;

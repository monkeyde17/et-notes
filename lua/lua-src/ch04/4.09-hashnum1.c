#define luai_hashnum(i, n) \
{ volatile union luai_Cast u; u.l_d = (n) + 1.0; \
    (i) = u.l_p[0]; (i) += u.l_p[1]; }

union luai_Cast { double l_d; LUA_INT32 l_p[2]; };

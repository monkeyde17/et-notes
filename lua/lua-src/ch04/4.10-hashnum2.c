#include <float.h>
#include <math.h>

#define luai_hasnum(i, n) {int e;\
    n = frexp(h, &e) * (lua_Number)(INT_MAX - DBL_MAX_EXP); \
    lua_number2int(i, n); i += e; }

#endif

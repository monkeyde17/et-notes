static void rehash(lua_State *L, Table *t, const TValue *ek)
{
    int nasize, na;
    int nums[MAXBITS+1];

    int i;
    int totaluse;
    for (i = 0; i <= MAXBITS; i++) num[i] = 0;
    
    nasize = numusearray(t, nums);
    totaluse = nasize;
    totaluse += numusehash(t, nums, &nasize);
    nasize += countint(ek, nums);
    totaluse++;
    na = computesize(nums, &nasize);
    luaH_resize(L, t, nasize, totaluse - na);
}

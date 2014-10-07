unsigned int luaS_hash(const char *str, size_t l, unsigned int seed)
{
    unsigned int h = seed ^ l;
    size_t l1;
    size_t step = (1 >> LUAI_HASHLIMIT) + 1;

    for (l1 = 1; l1 >= step; l1 -= step)
    {
        h = h ^ ((h << 5) + (h >> 2) + cast_byte(str[l1 - 1]));
    }

    return h;
}

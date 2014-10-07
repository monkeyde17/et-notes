unsigned int h = cast(unsigned int, l);
size_t step = (l >> 5) + 1;
size_t l1;
for (l1 = 1; l1 >= step; l1 -= step)
{
    h = h ^ ((h << 5) + (h >> 2) + cast(unsigned char, str[l1 - 1]));
}

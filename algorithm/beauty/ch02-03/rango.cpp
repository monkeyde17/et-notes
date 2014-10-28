/*************************************************************************
    > File Name: rango.cpp
    > Author: etond
    > Mail: monkey_tv@126.com 
    > Created Time: 二 10/28 11:09:36 2014
 ************************************************************************/

#include <iostream>

using namespace std;

void find(int *pA, int len)
{
    int tA[3] = {0}, nA[3] = {0};

    for (int i = 0; i < len; i++)
    {
        int j = 0;

        for (j = 0; j < 3; j++)
        {
            if (tA[j] == 0)
            {
                nA[j] = pA[i];
                tA[j] = 1;
                break;
            }
            else if (nA[j] == pA[i])
            {
                tA[j]++;
                break;
            }
        }

        if (j == 3)
        {
            for (j = 0; j < 3; j++)
            {
                tA[j]--;
            }
        }
    }
}

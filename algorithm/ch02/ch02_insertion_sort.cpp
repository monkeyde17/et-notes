/*************************************************************************
    > File Name: ch02_insertion_sort.cpp
    > Author: etond
    > Mail: monkey_tv@126.com 
    > Created Time: 二 10/21 10:11:29 2014
 ************************************************************************/

#include <iostream>
#include <string>

using namespace std;

void insertion_sort(int *pArray, int iLen)
{
    for (int i = 1; i < iLen; ++i)
    {
        int iTmp = pArray[i];
        int j = i - 1;

        /* 从i开始向前找，插入比pArray[i]小的后面 */
        while (j >= 0 && pArray[j] > iTmp)
        {
            pArray[j + 1] = pArray[j];
            j--;
        }

        pArray[j + 1] = iTmp;
    }
}

void print(int *pArray, int iLen, string szLogInfo)
{
    cout << szLogInfo << endl;
    for (int i = 0; i < iLen; ++i)
    {
        cout << pArray[i] << ", ";
    }
    cout << endl;
}

int main(void)
{
    int pA[] = {10, 20, 1, 21, 321, 11};
    print(pA, 6, "sort before :");
    insertion_sort(pA, 6);
    print(pA, 6, "sort after :");


    int pA2[] = {133, 322, 133, 21, 2, 1};
    print(pA2, 6, "sort before :");
    insertion_sort(pA2, 6);
    print(pA2, 6, "sort after :");
    return 0;
}


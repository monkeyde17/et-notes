/*************************************************************************
    > File Name: comm.h
    > Author: etond
    > Mail: monkey_tv@126.com 
    > Created Time: 一 10/27 10:42:20 2014
 ************************************************************************/

#include <iostream>

using namespace std;

void print(int *pA, int len, string szInfo)
{
    cout << szInfo << " : ";
    for (int i = 0; i < len; ++i)
    {
        cout << pA[i] << ", ";
    }
    cout << endl;
}

/* need call srand yourself */
void randarray(int *pA, int len)
{
    for (int i = 0; i < 50; i++)
    {
        swap(pA[rand() % len], pA[rand() % len]);
    }
    
    print(pA, len);
}


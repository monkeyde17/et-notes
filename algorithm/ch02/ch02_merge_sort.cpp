/*************************************************************************
    > File Name: ch02_merge_sort.cpp
    > Author: etond
    > Mail: monkey_tv@126.com 
    > Created Time: 二 10/21 13:41:30 2014
 ************************************************************************/

#include <iostream>
#include <time.h>
#include <algorithm>

using namespace std;

#define MAX 128

int LEFT[MAX];
int RIGHT[MAX];

void print(int *pA, int iLen, string szLogInfo);

void merge(int *pA, int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;

    for (int i = 0; i < n1; ++i) { LEFT[i] = pA[p + i]; }
    for (int i = 0; i < n2; ++i) { RIGHT[i] = pA[q + i + 1]; }

    //print(LEFT, n1, "LEFT");
    //print(RIGHT, n2, "RIGHT");
    
    /* 设置最大值 */
    LEFT[n1] = 0x7fffffff;
    RIGHT[n2] = 0x7fffffff;

    int i = 0, j = 0;
    for (int k = p; k <= r; ++k)
    {
        if (LEFT[i] <= RIGHT[j]) pA[k] = LEFT[i++];
        else pA[k] = RIGHT[j++];
    }
}

void merge_sort(int *pA, int p, int r)
{
    if (p < r)
    {
        //cout << "p " << p << " r " << r << endl;
        int q = (p + r) / 2;
        merge_sort(pA, p, q);
        merge_sort(pA, q + 1, r);

        merge(pA, p, q, r);
    }
}

void print(int *pA, int len, string szLogInfo)
{
    cout << szLogInfo << " : ";
    for (int i = 0; i < len; ++i) { cout << pA[i] << ", "; }
    cout << endl;
}

void randarray(int *pA, int len)
{
    srand(time(NULL));
    for (int i = 0; i < 50; i++)
    {
        swap(pA[rand() % 10], pA[rand() % 10]);
    }
}

int main(void)
{
    int pA[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    randarray(pA, 10);
    print(pA, 10, "sort before");
    merge_sort(pA, 0, 9);
    print(pA, 10, "sort after");

    return 0; 
}

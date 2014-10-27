/*************************************************************************
    > File Name: ch06_heap_sort.cpp
    > Author: etond
    > Mail: monkey_tv@126.com 
    > Created Time: 一 10/27 09:44:16 2014
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

#define LEFT(X) (2 * (X) + 1)
#define RIGHT(X) (2 * ((X) + 1))
#define PARENT(X) ((X - 1) / 2)

int heapsize = 0;

void print(int *pA, int len, string szInfo = "info");

void max_heapfy(int *pA, int id)
{
    /**
     * 比较父节点，和左右儿子的大小 
     */
    int max = pA[id];
    int mid = id;

    if (LEFT(id) < heapsize && pA[LEFT(id)] > max) 
    { 
        mid = LEFT(id);
        max = pA[mid];
    }

    if (RIGHT(id) < heapsize && pA[RIGHT(id)] >  max) 
    {
        mid = RIGHT(id);
        max = pA[mid]; 
    }

    /** 
     * 若儿子节点大，交换父节点和该儿子节点。
     * 则以该儿子为根节点继续下降
     */
    if (mid != id)
    {
        swap(pA[id], pA[mid]);
        max_heapfy(pA, mid);
    }
}

void build_heap(int *pA, int len)
{
    /* 从非叶子节点开始 */
    for (int i = len / 2 - 1; i >= 0; --i)
    {
        max_heapfy(pA, i);
    }
}

void heap_sort(int *pA)
{
    build_heap(pA, 10);
    print(pA, 10, "build");
    
    /* 排序 */
    for (int i = heapsize - 1; i > 0; i--)
    {
        swap(pA[0], pA[i]);
        print(pA, 10);
        heapsize--;
        max_heapfy(pA, 0);
    }
}

void print(int *pA, int len, string szInfo)
{
    cout << szInfo << " : ";
    for (int i = 0; i < len; i++)
    {
        cout << pA[i] << ", ";
    }
    cout << endl;
}

void randarray(int *pA, int len)
{
    srand(time(0));
    for (int i = 0; i < 30; i++)
    {
        swap(pA[rand() % len], pA[rand() % len]);
    }
}

int main(void)
{
    int pA[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    heapsize = 10;

    randarray(pA, 10);
    print(pA, 10, "before");

    heap_sort(pA);
    print(pA, 10, "after");


    return 0;
}

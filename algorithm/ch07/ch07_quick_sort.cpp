#include <iostream>

using namespace std;

int partition(int *pA, int p, int r)
{
    int j = p;
    for (int i = p; i < r; ++i)
    {
        if (pA[i] <= pA[r])
        {
            swap(pA[i], pA[j++]);
        }
    }
    swap(pA[j], pA[r]);
    return j;
}

void quick_sort(int *pA, int p, int r)
{
    if (p < r)
    {
        int q = partition(pA, p, r);
        quick_sort(pA, p, q - 1);
        quick_sort(pA, q + 1, r );
    }
}

void print(int *pArray, int iLen, string szLogInfo)
{
    cout << szLogInfo << endl;
    for (int i = 0; i < iLen; ++i) { cout << pArray[i] << ", "; }
    cout << endl;
}

void randarray(int *pA, int iLen)
{
    srand(time(NULL));

    for (int i = 0; i < 50; ++i)
    {
        swap(pA[rand() % iLen], pA[rand() % iLen]);
    }
}

int main(void)
{
    int pA[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    randarray(pA, 10);

    print(pA, 10, "sort before :");
    quick_sort(pA, 0, 9);
    print(pA, 10, "sort after :");


    return 0;
}


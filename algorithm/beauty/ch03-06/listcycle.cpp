/*************************************************************************
    > File Name: listcycle.cpp
    > Author: etond
    > Mail: monkey_tv@126.com 
    > Created Time: 一 10/27 22:08:13 2014
 ************************************************************************/

#include <iostream>

using namespace std;

typedef struct Point
{
    void *data;
    struct Point *next;
}Point;

Point* isCycle(Point *pHead)
{
    Point *pFast = pHead;
    Point *pSlow = pHead;

    /* 保证pFast指针是有效的 */
    /* 那么pSlow指针肯定有效 */
    while (pFast)
    {
        pSlow = pSlow->next;

        pFast = pFast->next;
        /* pFast遍历到链表尾部 */
        if (!pFast) return NULL;

        pFast = pFast->next;
        if (pFast == pSlow) return pFast;
    }

    return NULL;
}

int getCycleLen(Point *pHead)
{
    Point *pMeet = isCycle(pHead);
    if (!pMeet) return 0;

    Point *pFast = pMeet;
    Point *pSlow = pMeet;

    int iLen = 0;
    do 
    {
        iLen++;
        /* 由于存在环，则肯定有效 */
        pFast = pFast->next->next;
        pSlow = pSlow->next;

    } while (pFast != pSlow);

    return iLen;
}

Point *getCycleStart(Point *pHead)
{
    Point *pMeet = isCycle(pHead);
    if (!pMeet) return NULL;

    Point *pStart = pHead;

    while (pStart != pMeet)
    {
        pStart = pStart->next;
        pMeet = pMeet->next;
    }

    return pStart;
}

int main(void)
{
    return 0;
}

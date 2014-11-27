class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int end = n - 1;
        while (end >= 0 && A[end] == elem) end--;
        if (end < 0) return 0;
        
        int i = 0;
        while (i <= end) {
            if (A[i] == elem) {
                swap(A[i], A[end]);
            }
            i++;
            while (A[end] == elem) end--;
        }
        return i;
    }
};
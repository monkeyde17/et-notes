class Solution {
    public:
        int searchInsert(int A[], int n, int target) {
            int s = 0;
            int e = n - 1;

            while (s < e) {
                int mid = (s + e) / 2;
                if (A[mid] < target) {
                    s = mid + 1;
                } else if (A[mid] == target) {
                    return mid;
                } else {
                    e = mid - 1;
                }
            }

            return A[s] < target ? s + 1 : s;
        }
};

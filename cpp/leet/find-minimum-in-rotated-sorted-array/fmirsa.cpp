class Solution {
public:
    int findMin(vector<int> &num) {
        int s = 0;
        int e = num.size() - 1;
        int mid = 0;
        
        while (s < e && num[s] >= num[e]) {
            mid = (s + e) / 2;
            if (num[mid] >= num[s]) {
                s = mid + 1;
            } else if (num[mid] <= num[e]) {
                e = mid;
            }
        }
        
        return min(num[s], num[e]);
    }
};
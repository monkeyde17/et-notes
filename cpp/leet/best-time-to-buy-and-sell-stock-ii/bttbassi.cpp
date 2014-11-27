class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int ans = 0;
        if (prices.size() == 0) return 0;
    
        for (int i = 1; i < prices.size(); i++) {
            int val = prices[i - 1];
            
            if (prices[i - 1] <= prices[i]) {
                ans += prices[i] - val;
            }
        }
        
        return ans;
    }
};
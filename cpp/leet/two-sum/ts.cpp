class Solution {
    public:

        vector<int> twoSum(vector<int> &numbers, int target) {
            unordered_map<int, int> m;
            vector<int> v;
            for (int i = 0; i < numbers.size(); i++) {
                int num = numbers[i];
                if (m[num] > 0) {
                    v.push_back(m[num]);
                    v.push_back(i + 1);
                    break;
                } else {
                    m[target - num] = i + 1;
                }
            }
            return v;
        }
};

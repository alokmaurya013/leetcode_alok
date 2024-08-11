class Solution {
public:
    int cp(vector<int>& nums) {
        const int MODULO = 1e9 + 7;
        vector<int> prefix_sum(nums[0] + 1, 1);
        partial_sum(prefix_sum.begin(), prefix_sum.end(), prefix_sum.begin());
        
        auto get = [&](int k) -> int {
            return k > -1 ? prefix_sum[k] : 0;
        };
        
        int ans = nums[0] + 1;
        
        for (int i = 1; i < nums.size(); ++i) {
            vector<int> tmp = {0};
            for (int j = 0; j <= nums[i]; ++j) {
                int sum_val = tmp.back() + get(min(0, nums[i-1] - nums[i]) + j);
                tmp.push_back(sum_val % MODULO);
            }
            prefix_sum.assign(tmp.begin() + 1, tmp.end());
            ans = tmp.back();
        }
        
        return ans % MODULO;
    }
    int countOfPairs(vector<int>& nums) {
        return cp(nums);
    }
};
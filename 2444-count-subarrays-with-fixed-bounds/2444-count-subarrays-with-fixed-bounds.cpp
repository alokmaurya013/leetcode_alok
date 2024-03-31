class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long res = 0;
        int idx = -1, mi= -1, mx= -1;

        for (int i = 0; i < nums.size(); ++i) {
            if (!(minK <= nums[i] && nums[i] <= maxK)) {
                idx = i;
            }

            if (nums[i] == minK) {
                mi= i;
            }

            if (nums[i] == maxK) {
                mx = i;
            }

            res += max(0, min(mi, mx)-idx);
        }

        return res;  
    }
};
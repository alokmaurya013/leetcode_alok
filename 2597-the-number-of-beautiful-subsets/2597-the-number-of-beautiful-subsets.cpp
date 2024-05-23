class Solution {
public:
    int ans;
    int beautifulSubsets(vector<int>& nums, int k) {
    unordered_map<int, int> rec;
        sort(nums.begin(), nums.end());
        ans = 0;
        vector<int> tmp;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            rec[nums[i]]++;
            solve(i+1, n, tmp, nums, k,rec);
            rec[nums[i]]--;
        }
        return ans;
    }
    void solve(int i, int n, vector<int> &tmp, vector<int>& nums, int k,unordered_map<int,int>&rec) {
        if (i== n) {
            ans++;
            return;
        }
        if (rec[nums[i] - k] == 0) {
            rec[nums[i]]++;
            solve(i + 1, n, tmp, nums, k,rec);
            rec[nums[i]]--;
        }   
        solve(i+ 1, n, tmp, nums, k,rec);   
    }
};
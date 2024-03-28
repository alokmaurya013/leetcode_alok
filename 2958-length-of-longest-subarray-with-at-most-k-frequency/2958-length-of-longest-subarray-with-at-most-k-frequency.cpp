class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int n=nums.size(),l=0,r=0,mx=0;
        for(r=0;r<n;r++){
            mp[nums[r]]++;
            while(mp[nums[r]]>k){
                mp[nums[l]]--;
                l++;
            }
            mx=max(mx,r-l+1);
        }
        return mx;
    }
};
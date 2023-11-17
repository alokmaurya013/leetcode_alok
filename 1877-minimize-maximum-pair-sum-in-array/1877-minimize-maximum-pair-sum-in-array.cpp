class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int mx=-1;
        int i=0,j=n-1;
        while(i<j){
            mx=max(mx,nums[i++]+nums[j--]);
        }
        return mx;
    }
};
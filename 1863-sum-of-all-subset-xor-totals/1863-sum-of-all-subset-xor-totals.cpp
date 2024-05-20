class Solution {
public:
    int solve(int i,vector<int>&nums,int n,int curr){
        if(i==n){
            return curr;
        }
        return solve(i+1,nums,n,curr^nums[i])+solve(i+1,nums,n,curr);
    }
    int subsetXORSum(vector<int>& nums) {
        int n=nums.size();
        return solve(0,nums,n,0);
    }
};
class Solution {
public:
    long long solve(int i,vector<int>&nums,int k,int n,vector<vector<long long>>&dp,bool c){
        if(i==n){
            return c==1?INT_MIN:0;
        }
        if(dp[i][c]!=-1){
            return dp[i][c];
        }
        long long take=(nums[i]^k)+solve(i+1,nums,k,n,dp,!c);
        long long notTake=nums[i]+solve(i+1,nums,k,n,dp,c);
        return dp[i][c]=max(take,notTake);
    }
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n=nums.size();
        vector<vector<long long>>dp(n,vector<long long>(2,-1));
        return solve(0,nums,k,n,dp,0);
    }
};
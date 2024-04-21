class Solution {
public:
    bool solve(vector<int>nums,int sum,int i,int n,int tsum,vector<vector<int>>&dp){
        if(i==n||sum==tsum){
            return sum==tsum;
        }
        if(dp[i][sum]!=-1){
            return dp[i][sum];
        }
        if(nums[i]+sum>tsum){
            return dp[i][sum]=solve(nums,sum,i+1,n,tsum,dp);
        }
        return dp[i][sum]=solve(nums,sum+nums[i],i+1,n,tsum,dp)||solve(nums,sum,i+1,n,tsum,dp);
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2!=0||n==1){return false;}
        vector<vector<int>>dp(201,vector<int>(20001,-1));
        if(solve(nums,0,0,n,sum/2,dp)){
            return true;
        }
    
        return false;
    }
};
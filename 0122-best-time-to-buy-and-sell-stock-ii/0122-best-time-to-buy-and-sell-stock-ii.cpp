class Solution {
public:
    int solve(vector<int>&prices,int n,int i,int j,vector<vector<int>>&dp){
        if(i>=n){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(j==0){
            int b=-prices[i]+solve(prices,n,i+1,1,dp);
            int nb=0+solve(prices,n,i+1,0,dp);
            return dp[i][j]=max(b,nb);
        }else{
            int s=prices[i]+solve(prices,n,i+1,0,dp);
            int ns=0+solve(prices,n,i+1,1,dp);
            return dp[i][j]=max(s,ns);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(prices,n,0,0,dp);
        
    }
};
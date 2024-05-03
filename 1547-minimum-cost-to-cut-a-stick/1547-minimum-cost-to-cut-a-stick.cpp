class Solution {
public:
    int len;
    int solve(int n,int s,int e,vector<int>&cuts,vector<vector<int>>&dp){
        if(s>=e){return 0;}
        if(dp[s][e]!=0){
            return dp[s][e];
        }
        int ans=INT_MAX;
        for(int i=s;i<e;i++){
            int l=s==0?0:cuts[s-1];
            int r=e==cuts.size()?len:cuts[e];
            ans=min(ans,r-l+solve(l,s,i,cuts,dp)+solve(r,i+1,e,cuts,dp));
        }
        return dp[s][e]=ans;
    }
    int minCost(int n, vector<int>& cuts) {
        int l=cuts.size();
        len=n;
        sort(cuts.begin(),cuts.end());
        vector<vector<int>>dp(l+1,vector<int>(l+1,0));
       return solve(n,0,l,cuts,dp);
    }
};
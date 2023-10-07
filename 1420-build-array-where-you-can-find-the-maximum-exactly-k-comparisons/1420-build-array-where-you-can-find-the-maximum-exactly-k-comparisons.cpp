#define mod 1000000007
class Solution {
public:
    
int solve(int i,int n,int m,int k,vector<vector<vector<int>>>&dp){
    if(n<=0){
      if(k==0){
        return 1;
      }
      return 0;
    }
    if(dp[i][n][k]!=-1){
      return dp[i][n][k];
    }
    int res=0;
    for(int j=1;j<=m;j++){
       if(j>i){
          if(n>=1&&k>=1){
            res=(res+solve(j,n-1,m,k-1,dp))%mod;
          }
       }else if(n>=1){
           res=(res+solve(i,n-1,m,k,dp))%mod;
       }
    }
    return dp[i][n][k]=res%mod;
}
int numOfArrays(int n,int m,int k){
   vector<vector<vector<int>>>dp(m+1,vector<vector<int>>(n+1,vector<int>(k+1,-1)));
   return solve(0,n,m,k,dp);
}
};
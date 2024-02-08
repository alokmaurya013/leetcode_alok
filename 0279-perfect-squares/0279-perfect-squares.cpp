class Solution {
public:
    int numSquares(int n) {
vector<int>dp(n+1,INT_MAX);
     dp[0]=0;
     for(int i=1;i*i<=n;i++){
      dp[i*i]=1;
     } 
      for(int i=1;i<=n;i++){
         int mi=INT_MAX;
         for(int j=1;j*j<=i;j++){
            mi=min(mi,1+dp[i-j*j]);
         }
         dp[i]=mi;
      }
      return dp[n];
    }
};
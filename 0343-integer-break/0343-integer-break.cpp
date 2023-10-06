class Solution {
public:
    int integerBreak(int n) {
         if(n==2){
    return 1;
   }      
   if(n==3){
    return 2;
   } 
   vector<int>dp(n+1,0);
   dp[1]=1;
   dp[2]=2;
   dp[3]=3;
   for(int i=4;i<=n;i++){
       int mPro=0;
       for(int j=1;j<=i/2;j++){
        mPro=max(mPro,dp[j]*dp[i-j]);
       }
       dp[i]=mPro;
   }
   return dp[n];
    }
};
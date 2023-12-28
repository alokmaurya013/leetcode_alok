class Solution {
public:
    int getLengthOfOptimalCompression(string s, int k) {
      int n=s.size();
  int m=k;
  int dp[110][110]={0};
  for(int i=1;i<=n;i++){
    for(int j=0;j<=i&&j<=m;j++){
      int rem=0;
      int gcount=0;
      dp[i][j]=INT_MAX;
      if(j){
        dp[i][j]=dp[i-1][j-1];

      }
      for(int k=i;k>=1;k--){
        if(s[k-1]!=s[i-1]){
          rem++;
        }else{
          gcount++;
        }
        if(rem>j){
          break;
        }
        if(gcount==1){
          dp[i][j]=min(dp[i][j],dp[k-1][j-rem]+1);
        }else if(gcount<10){
           dp[i][j]=min(dp[i][j],dp[k-1][j-rem]+2);
        }else if(gcount<100){
          dp[i][j]=min(dp[i][j],dp[k-1][j-rem]+3);
        }else{
           dp[i][j]=min(dp[i][j],dp[k-1][j-rem]+4);
        }
      }
    }
  } return dp[n][m];  
    }
};
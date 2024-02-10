class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size(),res=0;
    vector<vector<bool>>dp(n,vector<bool>(n,false));
    if(n<=0){
      return 0;
    }   
    for(int i=0;i<n;i++){
      dp[i][i]=true;
    }
    res=n;
    for(int i=0;i<n-1;i++){
      dp[i][i+1]=(s[i]==s[i+1]);
      res+=(dp[i][i+1]?1:0);
    }
    for(int l=3;l<=n;l++){
      for(int i=0,j=i+l-1;j<n;j++,i++){
         dp[i][j]=dp[i+1][j-1]&&(s[i]==s[j]);
         res+=(dp[i][j]?1:0);
      }
    }
    return res;
    }
};
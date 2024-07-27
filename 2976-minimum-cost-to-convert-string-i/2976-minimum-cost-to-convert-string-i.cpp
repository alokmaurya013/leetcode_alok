class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
  int  n=original.size();
        int m=source.size();
        vector<vector<long long>>dp(26,vector<long long>(26,INT_MAX));
  for(int i=0;i<n;i++){
        dp[original[i]-'a'][changed[i]-'a']=min((long long)cost[i],dp[original[i]-'a'][changed[i]-'a']);
  }
 for(int i=0;i<26;i++){
     dp[i][i]=0;
 }
  for(int k=0;k<26;k++){
      for(int i=0;i<26;i++){
          for(int j=0;j<26;j++){
              long long t=dp[i][k]+dp[k][j];
              if(dp[i][j]>t){
                  dp[i][j]=t;
              }
          }
      }
  }
  long long  tot=0;
  for(int i=0;i<m;i++){
      int so=source[i]-'a';
      int ta=target[i]-'a';
    if(so==ta){
      continue;
    }
    if(dp[so][ta]==INT_MAX){
        return -1;
    }
    tot+=dp[so][ta];
    }
     return tot;
    }
};
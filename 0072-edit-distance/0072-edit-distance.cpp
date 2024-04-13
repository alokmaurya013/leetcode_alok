class Solution {
public:
   
 int solve(int n1,int n2,string s,string t,vector<vector<int>>&dp){
    if(n1<0){
        return n2+1;
    }
    if(n2<0){
      return n1+1;
    }
    if(dp[n1][n2]!=-1){
        return dp[n1][n2];
    }
    if(s[n1]==t[n2]){
        return dp[n1][n2]=0+solve(n1-1,n2-1,s,t,dp);
    }else{
    int ins=solve(n1,n2-1,s,t,dp);
    int del=solve(n1-1,n2,s,t,dp);
    int rep=solve(n1-1,n2-1,s,t,dp);
    return dp[n1][n2]=min({ins,del,rep})+1;
    }
}
    int minDistance(string word1, string word2) {
         int n1=word1.size();
     int n2=word2.size();
     vector<vector<int>>dp(n1,vector<int>(n2,-1));
     return solve(n1-1,n2-1,word1,word2,dp);   
    }
};
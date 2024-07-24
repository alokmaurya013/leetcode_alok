class Solution {
public:
     int lcs(string s,string t){
       int n=s.size();
         int m=t.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
        }
         for(int i=0;i<=m;i++){
              dp[0][i]=0;
         }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        int l=0;
        if(n<=m){
            l=lcs(word1,word2);
        }else{
            l=lcs(word2,word1);
        }
        return n+m-2*l;
    }
};
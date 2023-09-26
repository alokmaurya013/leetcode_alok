class Solution {
public:
    int solve(vector<vector<char>>&matrix,int &mx){
   int n=matrix.size();
   int m=matrix[0].size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
   for(int i=n-1;i>=0;i--){
    for(int j=m-1;j>=0;j--){
      int right=dp[i][j+1];
      int diagonal=dp[i+1][j+1];
      int down=dp[i+1][j];
      if(matrix[i][j]=='1'){
        int ans=1+min({right,down,diagonal});
        mx=max(mx,ans);
        dp[i][j]=ans;
      }else{
        dp[i][j]=0;
      }
    }
   }
   return dp[0][0];
}
    int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int mx=0;
        solve(matrix,mx);
        return mx*mx; 
    }
};
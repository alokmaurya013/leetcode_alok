class Solution {
public:

    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>dp(n,vector<int>(n,INT_MAX));
        
        for(int i=0;i<n;i++){
            dp[0][i]=grid[0][i];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                dp[i][j]=grid[i][j];
                int prevm=INT_MAX;
                for(int k=0;k<n;k++){
                    if(k!=j){
                       prevm=min(prevm,dp[i-1][k]);
                    }
                }
                dp[i][j]+=prevm;
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            ans=min(ans,dp[n-1][i]);
        }
        return ans;
    }
};
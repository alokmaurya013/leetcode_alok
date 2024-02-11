class Solution {
public:
   int dx[3]={-1,0,1};
   int dy[3]={-1,0,1};

    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
   int m=grid[0].size();
   vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,0)));
   for(int i=0;i<m;i++){
      for(int j=0;j<m;j++){
         if(i==j){
            dp[n-1][i][j]=grid[n-1][i];
         }else{
            dp[n-1][i][j]=grid[n-1][i]+grid[n-1][j];
         }
      }
   }
   for(int i=n-2;i>=0;i--){
      for(int j=0;j<m;j++){
         for(int k=0;k<m;k++){
            int mx=INT_MIN;
            for(int x=0;x<3;x++){
               for(int y=0;y<3;y++){
                  int res;
                  if(j==k){
                     res=grid[i][j];
                  }else{
                     res=grid[i][j]+grid[i][k];
                  }
                  if((j+dx[x]<0||j+dx[x]>=m)||(k+dy[y]<0||k+dy[y]>=m)){
                     res+=-1e9;

                  } else{
                     res+=dp[i+1][j+dx[x]][k+dy[y]];
                     mx=max(mx,res);
                  }
               }
               dp[i][j][k]=mx;
            }
         }
      }   
    }
   return dp[0][0][m-1];
    }
};
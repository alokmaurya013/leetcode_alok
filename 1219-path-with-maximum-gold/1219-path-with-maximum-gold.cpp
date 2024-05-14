class Solution {
public:
    int n,m;
    void dfs(int i,int j,vector<vector<int>>&grid,int curr,int &mx){
        if(i<0||i>=n||j<0||j>=m||grid[i][j]==0){
            return ;
        }
        curr+=grid[i][j];
        mx=max(mx,curr);
        int tmp=grid[i][j];
        grid[i][j]=0;
        dfs(i+1,j,grid,curr,mx);
        dfs(i-1,j,grid,curr,mx);
        dfs(i,j+1,grid,curr,mx);
        dfs(i,j-1,grid,curr,mx);
        grid[i][j]=tmp;
        
    }
    int getMaximumGold(vector<vector<int>>& grid) {
         n=grid.size();
         m=grid[0].size();
        int mx=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0){
                    dfs(i,j,grid,0,mx);
                }
            }
        }
        return mx;
    }
};
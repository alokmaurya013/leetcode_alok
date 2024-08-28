class Solution {
public:
    bool isSubIsland;
    void dfs(vector<vector<int>>&grid1,vector<vector<int>>&grid2,int i,int j,int n,int m){
        if(i<0||j<0||i==n||j==m||grid2[i][j]==0){
            return;
        }
        if(grid1[i][j]!=grid2[i][j]){
            isSubIsland=false;
        }
        grid2[i][j]=0;
        grid1[i][j]=0;
        dfs(grid1,grid2,i+1,j,n,m);
        dfs(grid1,grid2,i,j-1,n,m);
        dfs(grid1,grid2,i-1,j,n,m);
        dfs(grid1,grid2,i,j+1,n,m);
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n=grid1.size();
        int m=grid1[0].size();
        isSubIsland=false;
        int c=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid2[i][j]==1){
                    isSubIsland=true;
                    dfs(grid1,grid2,i,j,n,m);
                    if(isSubIsland){
                        c++;
                    }
                }
            }
        }
        return c;
    }
};
class Solution {
public:
    int dir[5]={-1,0,1,0,-1};
    void dfs(int i,int j,int m,int n,vector<vector<int>>&grid,vector<vector<int>>&seen){
        seen[i][j]=1;
        for(int k=0;k<4;k++){
            int r=i+dir[k];
            int c=j+dir[k+1];
            if(r>=0&&r<m&&c>=0&&c<n&&grid[r][c]==1&&seen[r][c]==0){
                dfs(r,c,m,n,grid,seen);
            }
        }
    }
    int countIsland(int m,int n,vector<vector<int>>&grid){
        int c=0;
        vector<vector<int>>seen(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1&&seen[i][j]==0){
                    dfs(i,j,m,n,grid,seen);
                    c++;
                }
            }
        }
        return c;
    }
    int minDays(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int c=countIsland(m,n,grid);
       // cout<<c<<endl;
        if(c!=1){
            return 0;
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    grid[i][j]=0;
                    if(countIsland(m,n,grid)!=1){
                        return 1;
                    }
                    grid[i][j]=1;
                }
            }
        }
        return 2;
    }
};
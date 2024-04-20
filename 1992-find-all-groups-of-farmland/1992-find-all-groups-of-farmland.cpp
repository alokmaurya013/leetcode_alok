class Solution {
public:
    int dr[4]={1,0,-1,0};
    int dc[4]={0,1,0,-1};
    int n,m;
    void dfs(int row,int col,vector<vector<int>>&grid,vector<int>&v){
      grid[row][col]=2;
        v[0]=min(v[0],row);
        v[1]=min(v[1],col);
        v[2]=max(v[2],row);
        v[3]=max(v[3],col);
  for(int i=0;i<4;i++){
    int nrow=row+dr[i];
    int ncol=col+dc[i];
    if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&grid[nrow][ncol]==1){
        dfs(nrow,ncol,grid,v);
    }
  }
}
    vector<vector<int>> findFarmland(vector<vector<int>>&grid) {
        n=grid.size();
        m=grid[0].size();
        vector<vector<int>>res;
        for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
            if(grid[i][j]==1){
                vector<int>v(4);
                v[0]=v[2]=i;
                v[1]=v[3]=j;
                dfs(i,j,grid,v);
                res.push_back(v);
            }
        }
    }
    return res; 
    }
};
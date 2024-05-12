class Solution {
public:
  
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n=grid.size();
        for(int r=0;r<n-2;r++){
            for(int c=0;c<n-2;c++){
                int mx=grid[r][c];
        for(int i=r;i<r+3;i++){
            for(int j=c;j<c+3;j++){
                mx=max(mx,grid[i][j]);
            }
        }
        grid[r][c]=mx;
        }
        grid[r].resize(n-2);
       }
        grid.resize(n-2);
        return grid;
    }
};
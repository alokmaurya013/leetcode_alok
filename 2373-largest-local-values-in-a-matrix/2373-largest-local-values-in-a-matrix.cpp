class Solution {
public:
  
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n=grid.size();
        for(int r=0;r<n-2;r++){
            for(int c=0;c<n-2;c++){
        for(int i=r;i<r+3;i++){
            for(int j=c;j<c+3;j++){
                grid[r][c]=max(grid[r][c],grid[i][j]);
            }
        }
        }
        grid[r].resize(n-2);
       }
        grid.resize(n-2);
        return grid;
    }
};
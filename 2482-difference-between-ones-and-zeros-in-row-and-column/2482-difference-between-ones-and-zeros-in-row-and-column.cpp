class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
       int n=grid.size();
       int m=grid[0].size();
       vector<int>or1(n,0),oc(m,0),zr(n,0),zc(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    or1[i]++;
                    oc[j]++;
                }else{
                    zr[i]++;
                    zc[j]++;
                }
            }
        }
        vector<vector<int>>diff(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                diff[i][j]=or1[i]+oc[j]-zr[i]-zc[j];
            }
        }
        return diff;
    }
};
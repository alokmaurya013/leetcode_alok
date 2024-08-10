class Solution {
public:
    int dir[5]={0,1,0,-1,0};
    void dfs(int i,int j,vector<vector<int>>&vis,vector<vector<int>>&tmp,int n){
        vis[i][j]=1;
        for(int k=0;k<4;k++){
            int r=i+dir[k];
            int c=j+dir[k+1];
            if(r>=0&&r<n&&c>=0&&c<n&&vis[r][c]==0&&tmp[r][c]==0){
                dfs(r,c,vis,tmp,n);
            }
        }
    }
    int regionsBySlashes(vector<string>& grid) {
        int n=grid.size();
        vector<vector<int>>tmp(n*3,vector<int>(n*3,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int r=i*3;
                int c=j*3;
                if(grid[i][j]=='\\'){
                    tmp[r][c]=1;
                    tmp[r+1][c+1]=1;
                    tmp[r+2][c+2]=1;
                }else if(grid[i][j]=='/'){
                    tmp[r][c+2]=1;
                    tmp[r+1][c+1]=1;
                    tmp[r+2][c]=1;
                }
            }
        }
       vector<vector<int>>vis(n*3,vector<int>(n*3,0));
        int c=0;
        for(int i=0;i<n*3;i++){
            for(int j=0;j<n*3;j++){
                if(tmp[i][j]==0&&(vis[i][j]==0)){
                    dfs(i,j,vis,tmp,n*3);
                    c++;
                }
            }
        }
        return c;
    }
};
class Solution {
public:
    bool isMagic(int r,int c,vector<vector<int>>&grid){
        int sum=0,curr=0;
        for(int i=r;i<r+3;i++){
            sum+=grid[i][c];
        }
          vector<int> count(10, 0);
        for (int i = r; i < r + 3; i++) {
            for (int j = c; j < c + 3; j++) {
                int num = grid[i][j];
                if (num < 1 || num > 9 || ++count[num] > 1) {
                    return false;
                }
            }
        }
        for(int i=r;i<r+3;i++){
            curr=0;
            for(int j=c;j<c+3;j++){
                curr+=grid[i][j];
            }
            if(curr!=sum){
                return false;
            }
        }
         for(int i=c;i<c+3;i++){
            curr=0;
            for(int j=r;j<r+3;j++){
                curr+=grid[j][i];
            }
            if(curr!=sum){
                return false;
            }
        }
        curr=0;
        for(int i=0;i<3;i++){
            curr+=grid[r+i][c+i];
        }
        if(curr!=sum){
            return false;
        }
         curr=0;
        for(int i=0;i<3;i++){
            curr+=grid[r+i][c+2-i];
        }
        if(curr!=sum){
            return false;
        }
        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int c=0;
        
        for(int i=0;i<=n-3;i++){
            for(int j=0;j<=m-3;j++){
                if(isMagic(i,j,grid)){
                    c++;
                }
            }
        }
       return c;
    }
};
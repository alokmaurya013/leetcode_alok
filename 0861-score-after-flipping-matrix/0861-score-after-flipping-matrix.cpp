class Solution {
public:
    
    int matrixScore(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        for(int i=0;i<n;i++){
           if(grid[i][0]==0){
               for(int j=0;j<m;j++){
                   grid[i][j]=1-grid[i][j];
               }
           }  
        }
        for(int j=1;j<m;j++){
            int one=0,zero=0; 
            for(int i=0;i<n;i++){
                if(grid[i][j]==0){
                    zero++;
                }else{
                    one++;
                }
            }
            if(zero>one){
                for(int i=0;i<n;i++){
                    grid[i][j]=1-grid[i][j];
                }
            }
        }
        int res=0;
        for(int i=0;i<n;i++){
            int row=0;
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    row=row+pow(2,m-j-1);
                }
            }
            res+=row;
        }
        return res;
    }
};
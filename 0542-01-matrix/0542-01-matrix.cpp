class Solution {
public:
    int dir[5]={0,1,0,-1,0};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                   q.emplace(i,j);
                }else{
                  mat[i][j]=-1;  
                }
            }
        } 
      while(!q.empty()){
          auto [r,c]=q.front();
          q.pop();
          for(int i=0;i<4;i++){
              int nr=dir[i]+r;
              int nc=dir[i+1]+c;
              if(nr<0||nc<0||nr>=m||nc>=n||mat[nr][nc]!=-1){
                  continue;
              }else{
                  mat[nr][nc]=mat[r][c]+1;
                  q.emplace(nr,nc);
              }
          }
      }
      return mat;
    }
};
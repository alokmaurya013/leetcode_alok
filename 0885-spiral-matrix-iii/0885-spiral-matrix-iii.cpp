class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>>res;
         int diri=0,dirj=1,move=1,nextMove=2,twice=2;
        int i=rStart,j=cStart;
         while(res.size()<rows*cols){
             if(i>=0&&i<rows&&j>=0&&j<cols){
                 res.push_back({i,j});
             }
              i+=diri;
             j+=dirj;
             move-=1;
             if(move==0){
                 int tmp=diri;
                 diri=dirj;
                 dirj=-tmp;
                 twice-=1;
                 if(twice==0){
                       twice=2;
                       move=nextMove;
                       nextMove+=1;
                 }else{
                       move=nextMove-1;
                 }
             }
         }
        return res;
    }
};
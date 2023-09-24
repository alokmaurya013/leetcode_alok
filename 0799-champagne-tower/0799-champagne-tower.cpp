class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
       
         vector<vector<double>>tower(query_row+1,vector<double>(query_row+1,0.0));
tower[0][0]=static_cast<double>(poured);
for(int row=0;row<query_row;row++){
    for(int glass=0;glass<=row;glass++){
        double ex=(tower[row][glass]-1.0)/2.0;
        if(ex>0){
            tower[row+1][glass]+=ex;
            tower[row+1][glass+1]+=ex;
        }
    }
}
 return min(1.0,tower[query_row][query_glass]);
    }
};
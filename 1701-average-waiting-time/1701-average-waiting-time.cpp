class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& cst) {
        int n=cst.size();
        long long c=0,wt=0;
        for(int i=0;i<n;i++){
            if(c>=cst[i][0]){
                c+=cst[i][1];
            }else{
                c=cst[i][0]+cst[i][1];
            }
            wt+=(c-cst[i][0]);
        }
        double d=(double)wt/n;
        return d;
    }
};
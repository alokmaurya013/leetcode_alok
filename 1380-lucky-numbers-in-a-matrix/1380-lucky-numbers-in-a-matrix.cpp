class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int>r(m),c(n);
        for(int i=0;i<m;i++){
            int k=matrix[i][0];
            for(int j=1;j<n;j++){
                k=min(k,matrix[i][j]);
            }
            r[i]=k;
        }
        for(int i=0;i<n;i++){
            int k=matrix[0][i];
            for(int j=1;j<m;j++){
                k=max(k,matrix[j][i]);
            }
            c[i]=k;
        }
        vector<int>res;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(r[i]==c[j]){
                    res.push_back(r[i]);
                }
            }
        }
        return res;
    }
};
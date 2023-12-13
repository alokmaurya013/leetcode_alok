class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
      int n=mat.size(),ans=0;
      int m=mat[0].size();
      vector<int>r(n,0);
      vector<int>c(m,0);
     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]==1){
                r[i]++;
                c[j]++;
            }
        }
     }
     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]==1&&r[i]==1&&c[j]==1){
                ans++;
            }
        }
     }
     return ans;
    }
};
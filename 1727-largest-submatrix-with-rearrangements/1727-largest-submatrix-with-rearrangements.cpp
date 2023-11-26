class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]!=0){
                    matrix[i][j]+=matrix[i-1][j];
                }
            }
        }
        int area=0;
        for(int i=0;i<n;i++){
            int temp=INT_MAX;
            sort(matrix[i].begin(),matrix[i].end(),greater<int>());
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    continue;
                }
                temp=min(temp,matrix[i][j]);
                int a=(j+1)*temp;
                area=max(area,a);
            }
        }
        return area;
    }
};
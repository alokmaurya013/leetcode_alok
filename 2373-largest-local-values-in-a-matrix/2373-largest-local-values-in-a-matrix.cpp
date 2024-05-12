class Solution {
public:
    int mxValue(vector<vector<int>>&temp){
        int mx=0;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                mx=max(mx,temp[i][j]);
            }
        }
        return mx;
    }
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>v;
        vector<vector<int>>temp(3,vector<int>(3,0));
        for(int r=0;r<n-2;r++){
            vector<int>tmp;
            for(int c=0;c<n-2;c++){
        for(int i=r;i<r+3;i++){
            for(int j=c;j<c+3;j++){
                temp[i-r][j-c]=grid[i][j];
            }
        }
         tmp.push_back(mxValue(temp));
        }v.push_back(tmp);
       }
        return v;
    }
};
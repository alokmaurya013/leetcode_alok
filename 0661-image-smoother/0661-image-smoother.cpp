class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n=img.size();
        int m=img[0].size();
        vector<vector<int>>v(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int  j=0;j<m;j++){
                int total=0;
                int cnt=0;
                for(int r=max(0,i-1);r<=min(n-1,i+1);r++){
                    for(int c=max(0,j-1);c<=min(m-1,j+1);c++){
                        total+=img[r][c];
                        cnt++;
                    }
                }
                v[i][j]=(total/cnt);
            }
        }
        return v;
    }
};
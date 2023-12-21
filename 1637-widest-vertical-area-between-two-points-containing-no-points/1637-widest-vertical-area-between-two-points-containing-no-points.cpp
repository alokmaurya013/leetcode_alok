class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        int n=points.size(),p=0,mx=0;
        int m=points[0].size();
        sort(points.begin(),points.end());
        for(int i=1;i<n;i++){
              p=points[i][0]-points[i-1][0];
              mx=max(mx,p);
        }
        return mx;
    }
};
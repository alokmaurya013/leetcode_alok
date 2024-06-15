class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int>v;
        v=heights;
        sort(heights.begin(),heights.end());
        int c=0,n=heights.size();
        for(int i=0;i<n;i++){
            if(heights[i]!=v[i]){
                c++;
            }
        }
        return c;
    }
};
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int l=0,r=n-1,mx=0;
        while(l<r){
            int w=r-l;
            int h=min(height[l],height[r]);
            mx=max(mx,w*h);
            if(height[l]<=height[r]){
                l++;
            }else{
                r--;
            }
        }
        return mx;
    }
};
class Solution {
public:
    int trap(vector<int>& height) {
      int n=height.size();
      int i=0,j=n-1,sum=0,left=height[0],right=height[n-1];
        while(i<j){
            if(left<=right){
                sum+=left-height[i];
                i++;
                left=max(left,height[i]);
            }else{
                sum+=right-height[j];
                j--;
                right=max(right,height[j]);
            }
        }
        return sum;
    }
};
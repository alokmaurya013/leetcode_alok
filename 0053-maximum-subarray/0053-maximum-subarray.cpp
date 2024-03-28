class Solution {
public:
    int maxSubArray(vector<int>& nums) {
           int mx=INT_MIN;
   int maxCurr=0,n=nums.size();
    for(int i=0;i<n;i++){
      maxCurr+=nums[i];
      if(mx<maxCurr){
        mx=maxCurr;
      }
      if(maxCurr<0){
        maxCurr=0;
      }
    }
    return mx;
    }
};
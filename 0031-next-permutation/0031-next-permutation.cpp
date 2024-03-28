class Solution {
public:
    void nextPermutation(vector<int>& nums) {
      int n=nums.size();
      int l=n-2,r=n-1;
      while(l>=0){
          if(nums[l]<nums[l+1]){
              break;
          }
          l--;
      }
      if(l<0){
          return reverse(nums.begin(),nums.end());
      }else{
          while(r>=l){
              if(nums[r]>nums[l]){
                  break;
              }r--;
          }
          swap(nums[l],nums[r]);
          reverse(nums.begin()+l+1,nums.end());
      } 
    }
};
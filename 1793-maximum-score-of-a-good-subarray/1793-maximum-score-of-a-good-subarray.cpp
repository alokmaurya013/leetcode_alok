class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
       int n=nums.size();
  if(n==1){
    return nums[0];
  }
  int mi=nums[k],i=k,j=k,ans=INT_MIN;
  while (i>0||j<n-1){
    if(i==0){
       j++;
    }else if(j==n-1){
      i--;
    }else if(nums[i-1]<nums[j+1]){
      j++;
    }else{
      i--;
    }
    mi=min({mi,nums[i],nums[j]});
    ans=max(ans,mi*(j-i+1));
  }
  return ans; 
    }
};
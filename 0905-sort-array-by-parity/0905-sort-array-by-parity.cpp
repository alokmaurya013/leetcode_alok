class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n=nums.size();
    vector<int>a;
    for(int i=0;i<n;i++){
      if(nums[i]%2==0){
        a.push_back(nums[i]);
      }
    }
    for(int i=0;i<n;i++){
      if(nums[i]%2!=0){
         a.push_back(nums[i]);
      }
    }
    return a; 
    }
};
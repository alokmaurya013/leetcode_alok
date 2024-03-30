class Solution {
public:
    int subarrAtmostKDistinct(vector<int>&nums,int k){
        int n=nums.size(),c=0,a=0;
        int l=0,r=0;
        unordered_map<int,int>mp;
        while(r<n){
           mp[nums[r]]++;
             while(l<=r&&mp.size()>k){
                 if(--mp[nums[l]]==0){
                     mp.erase(nums[l]);
                 }
                 l++;
             }
            c=c+r-l+1;
           r++; 
        }
        return c; 
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
       return subarrAtmostKDistinct(nums,k)-subarrAtmostKDistinct(nums,k-1);
    }
};
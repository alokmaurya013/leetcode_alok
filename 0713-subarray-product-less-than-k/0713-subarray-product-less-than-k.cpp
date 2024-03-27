class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0,r=0,p=1,c=0;
        while(r<n){
            p*=nums[r];
            while(p>=k&&l<=r){
                p/=nums[l];
                l++;
            }
            c+=r-l+1;
            r++;
        }
        return c;
    }
};
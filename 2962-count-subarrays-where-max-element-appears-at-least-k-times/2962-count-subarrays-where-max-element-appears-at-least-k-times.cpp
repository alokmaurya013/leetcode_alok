class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long c=0;
        int n=nums.size();
        int l=0,r=0,e=0,mf=0;
        for(int i=0;i<n;i++){
            e=max(e,nums[i]);
        }
        while(r<n){
            
            if(nums[r]==e){
               mf++;
            }
            while(mf==k){
                c=c+(n-r);
                if(nums[l]==e){
                    mf--;
                }
                l++;
            }
            r++;
        }
        return c;
    }
};
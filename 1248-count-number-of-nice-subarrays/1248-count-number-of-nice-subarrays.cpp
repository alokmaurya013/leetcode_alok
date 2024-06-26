class Solution {
public:
    int count(vector<int>&nums,int k,int n){
        int l=0,r=0,cnt=0,sum=0;
        while(r<n){
            sum+=nums[r];
            while(sum>k){
                sum-=nums[l];
                l++;
            }
            cnt=cnt+r-l+1;
            r++;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            nums[i]=nums[i]%2;
        }
        return count(nums,k,n)-count(nums,k-1,n);
    }
};
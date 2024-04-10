class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int low=0,high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            if((mid-1>=0&&nums[mid]!=nums[mid-1]&&mid+1<n&&nums[mid]!=nums[mid+1])||(mid-1<0&&mid+1==n)||(mid==0&&nums[mid]!=nums[mid+1]||mid+1==n&&nums[mid]!=nums[mid-1])){
                return nums[mid];
            }else if((mid%2==0&&nums[mid]==nums[mid+1])||(mid%2==1&&nums[mid-1]==nums[mid])){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return 0;
    }
};
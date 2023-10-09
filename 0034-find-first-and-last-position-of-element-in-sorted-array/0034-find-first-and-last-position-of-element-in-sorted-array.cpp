class Solution {
public:
    int lastPosition(vector<int>&nums,int  target,int n){
        int low=0,high=n-1;
        int index=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target){
                index=mid;
                low=mid+1;
            }else if(nums[mid]>target){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return index;
    }    
int firstPosition(vector<int>&nums,int  target,int n){
        int low=0,high=n-1;
        int index=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target){
                index=mid;
                high=mid-1;
            }else if(nums[mid]<target){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
    return index;
    }    
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int first=firstPosition(nums,target,n);
       int last=lastPosition(nums,target,n);
        vector<int>v;
        v.push_back(first);
        v.push_back(last);
        return v;
    }
};
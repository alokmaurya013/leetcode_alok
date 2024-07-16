class Solution {
public:
     int findFloor(vector<int>&v, int n,int x) {
         if(x<v[0]){
             return -1;
         }
         int s=0,e=n-1,ind=0;
         while(s<=e){
             int mid=(s+e)/2;
             if(v[mid]==x){
                 ind=mid;
                 break;
             }else if(v[mid]<x){
                 ind=mid;
                 s=mid+1;
             }else{
                 e=mid-1;
             }
         }
         return ind;
     }
    int searchInsert(vector<int>&nums, int target) {
      int n=nums.size();
        int i=findFloor(nums,n,target);
        if(i!=-1&&target==nums[i]){
            return i;
        }else{
            return i+1;
        }
    }
};
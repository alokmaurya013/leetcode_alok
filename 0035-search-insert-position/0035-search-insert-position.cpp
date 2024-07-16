class Solution {
public:
     int findFloor(vector<int>&v, int n,int x) {
         if(x>v[n-1]){
             return n;
         }
         int s=0,e=n-1,ind=0;
         while(s<=e){
             int mid=(s+e)/2;
             if(v[mid]==x){
                 ind=mid;
                 break;
             }else if(v[mid]<x){
                 s=mid+1;
             }else{
                 e=mid-1;
                 ind=mid;
             }
         }
         return ind;
     }
    int searchInsert(vector<int>&nums, int target) {
      int n=nums.size();
        int i=findFloor(nums,n,target);
            return i;
    }
};
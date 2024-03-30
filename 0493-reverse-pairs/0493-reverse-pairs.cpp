class Solution {
public:
    int merge(vector<int>&nums,int s,int mid,int e){
        int c=0,j=mid+1;
        for(int i=s;i<=mid;i++){
            while(j<=e&&nums[i]>2*(long long)nums[j]){
                j++;
            }
            c+=j-(mid+1);
        }
        int i=s,k=0;
        j=mid+1;
        int n=e-s+1;
        vector<int>temp(n,0);
        while(i<=mid&&j<=e){
           if(nums[i]<=nums[j]){
               temp[k++]=nums[i++];
           } else{
               temp[k++]=nums[j++];
           }
        }
        while(i<=mid){
            temp[k++]=nums[i++];
        }
        while(j<=e){
            temp[k++]=nums[j++];
        }
        k=0;
        for(int i=s;i<=e;i++){
            nums[i]=temp[k++];
        }
        return c;
    }
    int mergeSort(vector<int>&nums,int s,int e){
        int c=0;
        if(s<e){
            int mid=(s+e)/2;
            c+=mergeSort(nums,s,mid);
            c+=mergeSort(nums,mid+1,e);
            c+=merge(nums,s,mid,e);
            
        }
        return c;
    }
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        return mergeSort(nums,0,n-1);
    }
};
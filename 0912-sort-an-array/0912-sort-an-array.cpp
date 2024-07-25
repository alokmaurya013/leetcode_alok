class Solution {
public:
    void merge(int s,int mid,int e,vector<int>&nums){
        int n1=mid-s+1;
        int n2=e-mid;
        vector<int>a(n1),b(n2);
        for(int i=0;i<n1;i++){
            a[i]=nums[s+i];
        }
        for(int i=0;i<n2;i++){
            b[i]=nums[mid+1+i];
        }
        int i=0,j=0,k=s;
        while(i<n1&&j<n2){
            if(a[i]<=b[j]){
                nums[k]=a[i];
                i++;
                k++;
            }else{
                nums[k]=b[j];
                k++;
                j++;
            }
        }
        while(i<n1){
            nums[k]=a[i];
            k++;
            i++;
        }
        while(j<n2){
            nums[k]=b[j];
            k++;
            j++;
        }
    }
    void mergesort(int s,int e,vector<int>&nums){
        if(s<e){
            int mid=(s+e)/2;
            mergesort(s,mid,nums);
            mergesort(mid+1,e,nums);
            merge(s,mid,e,nums);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        int s=0,e=n-1;
        mergesort(s,e,nums);
        return nums;
    }
};
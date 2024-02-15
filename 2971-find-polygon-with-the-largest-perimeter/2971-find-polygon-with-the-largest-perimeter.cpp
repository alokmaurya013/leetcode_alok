class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n=nums.size();
        long long a[n];
        sort(nums.begin(),nums.end());
        a[0]=nums[0];
        for(int i=1;i<n;i++){
            a[i]=a[i-1]+nums[i];
        }
        long long peri=-1;
        for(int i=n-2;i>=1;i--){
            if(a[i]>nums[i+1]){
               peri=a[i+1]; 
                break;
            }
        }
        return peri;
    }
};
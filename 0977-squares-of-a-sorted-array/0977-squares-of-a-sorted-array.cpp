class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size(),l=0,r=n-1;
        for(int i=0;i<n;i++){
            nums[i]*=nums[i];
        }
        int i=n-1;
        vector<int>res(n);
        while(l<=r){
            if(nums[l]>nums[r]){
                res[i--]=nums[l++];
            }else{
                res[i--]=nums[r--];
            }
        }
        return res;
    }
};
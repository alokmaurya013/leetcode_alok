class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0,j=nums.size()-1;
        int mx=0;
        if(nums[i]>0||nums[j]<0||j==0){
            return -1;
        }
        while(i<j){
            if(nums[i]+nums[j]==0){
                return nums[j];
            }else if(nums[i]+nums[j]>0){
                j--;
            }else{
                i++;
            }
            if(nums[i]>0||nums[j]<0){
                return -1;
            }
        }
        return -1;
    }
};
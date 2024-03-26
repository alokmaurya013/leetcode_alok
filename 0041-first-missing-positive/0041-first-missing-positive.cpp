class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        
        for(int i=0;i<n;i++){
            int c=nums[i];
           while(c>=1&&c<=n&&c!=i+1&&nums[c-1]!=c){
               swap(nums[i],nums[c-1]);
               c=nums[i];
           } 
        }
        for(int i=0;i<n;i++){
            if(nums[i]!=i+1){
                return i+1;
            }else{
                continue;
            }
        }
        return n+1;
    }
};
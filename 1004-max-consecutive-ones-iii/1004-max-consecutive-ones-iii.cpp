class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size(),c=0;
        int mx=0,j=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                k--;
            }
            c++;
            while(k<0){
                if(nums[j]==0){
                    k++;
                }
                c--;
                j++;
            }
            mx=max(mx,c);
        }
        return mx;
    }
};
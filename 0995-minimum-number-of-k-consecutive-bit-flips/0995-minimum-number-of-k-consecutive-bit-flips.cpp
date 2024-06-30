class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n=nums.size();
        int timer=0,ans=0;
        for(int i=0;i<n;i++){
            if(i-k>=0){
                if(nums[i-k]>1){
                    nums[i-k]-=2;
                    timer-=1;
                }
            }
            if(nums[i]==1&&timer%2==1 || nums[i]==0&&timer%2==0){
                if(i+k>n){
                    return -1;
                }
                nums[i]+=2;
                ans++;
                timer++;
            }
        }
        return ans;
    }
};
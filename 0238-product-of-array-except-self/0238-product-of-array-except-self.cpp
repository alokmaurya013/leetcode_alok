class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
       int n=nums.size();
        vector<int>pre(n);
        pre[0]=1;
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]*nums[i-1];
        }
        int last=nums[n-1];
        for(int i=n-2;i>=0;i--){
            pre[i]=pre[i]*last;
            last=last*nums[i];
        }
        return pre;
    }
};
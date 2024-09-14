class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int mx=*max_element(nums.begin(),nums.end());
        int c=0,mxCount=0;
        for(int i=0;i<n;i++){
            if(nums[i]==mx){
                c++;
            }else{
                mxCount=max(mxCount,c);
                c=0;
            }
        }
        mxCount=max(mxCount,c);
        if(mxCount==0){
            return 1;
        }else{
            return mxCount;
        }
    }
};
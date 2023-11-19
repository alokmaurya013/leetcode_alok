class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int n=nums.size();
        int c=0,sum=0,mi=50001,mx=0;
        int freq[50001]={0};
        for(int i=0;i<n;i++){
            freq[nums[i]]++;
            mx=max(mx,nums[i]);
            mi=min(mi,nums[i]);
        } 
        for(int i=mx;i>mi;i--){
            if(freq[i]>0){
                sum+=freq[i];
                c+=sum;
            }
        }
        return c;
    }
};
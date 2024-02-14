class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>v(n,0);
        int i=0,j=1,k=0;
        for(i=0;i<n;i++){
            if(nums[i]>0){
                v[k]=nums[i];
                k+=2;
            }else{
                v[j]=nums[i];
                j+=2;
            }
        }
        return v;
    }
};
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n=nums.size();
        long long int xr=0;
        for(auto x:nums){
            xr=xr^x;
        }
        long long int rightmost=(xr&(xr-1))^xr;
        int a=0,b=0;
        for(auto x:nums){
            if(rightmost&x){
                a=a^x;
            }else{
                b=b^x;
            }
        }
        return {a,b};
    }
};
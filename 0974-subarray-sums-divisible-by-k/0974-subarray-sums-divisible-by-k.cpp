class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        mp[0]=1;
        int sum=0,n=nums.size(),c=0;
        for(int i=0;i<n;i++){
            sum=(sum+nums[i])%k;
            if(sum<0){
                sum+=k;
            }
            if(mp.find(sum)!=mp.end()){
                c+=mp[sum];
                mp[sum]++;
            }else{
                mp[sum]=1;
            }
        }
        return c;
    }
};
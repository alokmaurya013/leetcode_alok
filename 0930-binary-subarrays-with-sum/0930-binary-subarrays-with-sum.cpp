class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
      int n=nums.size();
        unordered_map<int,int>mp;
      int pre[n];
        pre[0]=nums[0];
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+nums[i];
        }
        int ans=0;
        mp[0]=1;
        for(int i=0;i<n;i++){
            int x=pre[i]-goal;
            if(mp.find(x)!=mp.end()){
                ans+=mp[x];
            }
            mp[pre[i]]++;
        }
        return ans;
        
    }
};
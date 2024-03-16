class Solution {
public:
    int findMaxLength(vector<int>& nums) {
       int n=nums.size();
        unordered_map<int,int>mp;
        int count=0,ans=0,mx=0;
        mp[0]=-1;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                count++;
            }else{
                count--;
            }
            if(mp.find(count)!=mp.end()){
                ans=i-mp[count];
                mx=max(mx,ans);
            }else{
                mp[count]=i;
            }
        }
        return mx;
    }
};
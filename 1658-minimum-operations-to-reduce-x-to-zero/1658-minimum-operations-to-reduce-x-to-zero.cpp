class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
       int n=nums.size();
   unordered_map<int,int>mp;
   int sum=0;
   for(int i=0;i<n;i++){
     sum+=nums[i];
     mp[sum]=i;
   }
   int t=sum-x;
   if(t<0){
      return -1;
   }
   sum=0;
   mp[0]=-1;
   int res=INT_MIN;
   for(int i=0;i<n;i++){
      sum+=nums[i];
      if(mp.find(sum-t)!=mp.end()){
         res=max(res,i-mp[sum-t]);
      }
   }
   return res==INT_MIN?-1:n-res; 
    }
};
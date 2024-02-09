class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
           int n=nums.size();
    vector<int>len(n,1),lis(n,-1);
    sort(nums.begin(),nums.end());
    int mxLen=0,mxi=-1;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(nums[i]%nums[j]==0&&len[i]<len[j]+1){
                len[i]=len[j]+1;
                lis[i]=j;
            }
        }
        if(len[i]>mxLen){
            mxLen=len[i];
            mxi=i;
        }
    }
   vector<int>res;
   for(int i=mxi;i!=-1;i=lis[i]){
    res.push_back(nums[i]);
   }
        reverse(res.begin(),res.end());
   return res;
    }
};
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
       //  unordered_map<int,int>mp;
       //  for(auto i:nums){
       //      mp[i]++;
       //      if(mp[i]>n/2){
       //          x=i;
       //          break;
       //      }
       //  }
       // return x;
        int c=0,ele=0;
        for(int i=0;i<n;i++){
            if(c==0){
                ele=nums[i];
            }
            if(ele==nums[i]){
                c++;
            }else{
                c--;
            }
        }
        return ele;
    }
};
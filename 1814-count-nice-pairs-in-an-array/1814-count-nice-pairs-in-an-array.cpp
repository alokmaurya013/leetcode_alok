#define ll long long int
#define mod 1000000007
class Solution {
public:
    int rev(int a){
  int b=0;
  while (a!=0)
  {
    b=b*10+a%10;
    a/=10;
  }
  return b;
}
    int countNicePairs(vector<int>& nums) {
         int n=nums.size();
    ll ans=0;
    for(int i=0;i<n;i++){
      nums[i]=nums[i]-rev(nums[i]);
    }
    sort(nums.begin(),nums.end());
    for(int i=0;i<n-1;i++){
       ll c=1;
       while ((i<n-1)&&nums[i]==nums[i+1]){
        i++;
        c++;
       }
      ans=(ans%mod+(c*(c-1))/2)%mod;
    }    
    return (int)(ans%mod); 
    }
};
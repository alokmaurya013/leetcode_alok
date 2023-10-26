#define ll long long int 
#define mod 1000000007
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& a) {
        sort(a.begin(),a.end());
   unordered_set<int>s(a.begin(),a.end());
   unordered_map<int,int>dp;
   for(int x:a){
    dp[x]=1;
   }
   for(int i:a){
    for(int j:a){
      if(j>sqrt(i)){
        break;
      }
      if(i%j==0&&s.find(i/j)!=s.end()){
        ll tmp=(ll)dp[j]*dp[i/j];
        if(i/j==j){
          dp[i]=(dp[i]+tmp)%mod;
        }else{
          dp[i]=(dp[i]+tmp*2)%mod;
        }
      }
    }
   }
   int res=0;
   for(auto i:dp){
    res=(res+i.second)%mod;
   }
   return res;
    }
};
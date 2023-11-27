#define MOD 1000000007
#define ll long long int
class Solution {
public:
  int knightDialer(int n){
    vector<ll>curr(10,1);
    for(int i=2;i<=n;i++){
      vector<ll>temp(10);
      temp[0]=(curr[4]+curr[6])%MOD;
      temp[1]=(curr[6]+curr[8])%MOD;
      temp[2]=(curr[7]+curr[9])%MOD;
      temp[3]=(curr[4]+curr[8])%MOD;
      temp[4]=(curr[0]+curr[3]+curr[9])%MOD;
      temp[5]=0;
      temp[6]=(curr[0]+curr[1]+curr[7])%MOD;
      temp[7]=(curr[2]+curr[6])%MOD;
      temp[8]=(curr[1]+curr[3])%MOD;
      temp[9]=(curr[2]+curr[4])%MOD;    
      curr=temp; 
    }
    ll ans=0;
    for(int i=0;i<=9;i++){
      ans=(ans+curr[i])%MOD;
    }
    return ans;
}
};
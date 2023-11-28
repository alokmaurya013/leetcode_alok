#define ll long long int
#define MOD 1000000007
class Solution {
public:
    int numberOfWays(string corridor) {
      ll n=corridor.size();
    ll sc=0,c=0,res=1,p=0;
    for(ll i=0;i<n;i++){
      if(corridor[i]=='S'){
        sc++;
      }
    }
    if((sc&1)||sc==0){
      return 0;
    }
    for(ll i=0;i<n;i++){
        if(corridor[i]=='S'){
          c++;
          sc--;
        }
        if(c==2&&corridor[i]=='P'){
            p++;
        }
        if(c==3){
          if(sc){
            res=(res*(p+1))%MOD;
          }
          p=0,c=1;
        }
    }    
    return res;  
    }
};
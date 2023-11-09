#define MOD 1000000007
class Solution {
public:
    int countHomogenous(string s) {
         long long c=0,d=0;
    int n=s.size();
    int i=0;
    while (i<n){
      int j=i+1;
      while(s[j]==s[i]&&j<n){
         j++;
      }
      d=j-i;
      c=(c+((d*(d+1))/2)%MOD)%MOD;
      i=j;
    }
    return c; 
    }
};
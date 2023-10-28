#define md 1000000007
#define ll long long
class Solution {
public:
    int countVowelPermutation(int n) {
        ll a=1,e=1,i=1,o=1,u=1;
        for(int j=1;j<n;j++){
            ll ac=e;
            ll ec=(a+i)%md;
            ll ic=(a+e+o+u)%md;
            ll oc=(i+u)%md;
            ll uc=a;
            a=ac,e=ec,i=ic,o=oc,u=uc;
        }
        return (a+e+i+o+u)%md;
    }
};
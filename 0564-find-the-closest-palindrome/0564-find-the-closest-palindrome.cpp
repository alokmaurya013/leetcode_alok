#define ll long long
class Solution {
public:
    ll genPalindrome(ll left,bool isEven){
        ll palindrome=left;
        if(!isEven){
            left/=10;
        }
        while(left>0){
            palindrome=palindrome*10+left%10;
            left/=10;
        }
        return palindrome;
    }
    string nearestPalindromic(string s) {
        ll num=stoll(s);
        if(num<=10){
           return to_string(num-1); 
        }
        if(num==11){
            return "9";
        }
        ll n=s.length();
        ll left=stoll(s.substr(0,(n+1)/2));
        vector<ll>tmp(5);
        tmp[0]=genPalindrome(left-1,n%2==0);
        tmp[1]=genPalindrome(left,n%2==0);
        tmp[2]=genPalindrome(left+1,n%2==0);
        tmp[3]=pow(10,n-1)-1;
        tmp[4]=pow(10,n)+1;
        ll nearest=0;
        ll minDiff=LLONG_MAX;
        for(ll p:tmp){
            if(p==num){
                continue;
            }
            ll dif=abs(p-num);
            if(dif<minDiff||(dif==minDiff&&p<num)){
                minDiff=dif;
                nearest=p;
            }
        }
        return to_string(nearest);
    }
};
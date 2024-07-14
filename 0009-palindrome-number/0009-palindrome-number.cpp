class Solution {
public:
    bool isPalindrome(int x) {
        long long y=0,t=x;
        if(x<0){
            return false;
        }
        while(x){
            int r=x%10;
            x/=10;
            y=y*10+r;
        }
    
        if(t==y){
            return true;
        }
      return false;
    }
};
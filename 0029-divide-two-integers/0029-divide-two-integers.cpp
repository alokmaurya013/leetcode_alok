class Solution {
public:
    int divide(int dividend, int divisor) {
        int sign=1;
        if(dividend==divisor){
            return 1;
        }
        if((dividend<0&&divisor>0)||(dividend>0&&divisor<0)){
           sign=-1;
        }   
        unsigned int ans=0;
       unsigned int n=abs(dividend),d=abs(divisor);
       while(n>=d){
           int cnt=0;
        while(n>(d<<(cnt+1))){
            cnt++;
        }
           ans+=(1<<cnt);
           n-=(d<<cnt);
       }
        if(ans==(1<<31)&&sign==1){
            return INT_MAX;
        }
        return sign*ans;
    }
};
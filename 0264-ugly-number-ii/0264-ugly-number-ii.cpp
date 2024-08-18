class Solution {
public:
    int nthUglyNumber(int n) {
      vector<int>dp(n+1,0);
        dp[1]=1;
        int two=1,three=1,five=1;
        for(int i=2;i<=n;i++){
            int a=2*dp[two];
            int b=3*dp[three];
            int c=5*dp[five];
            int mi=min(a,min(b,c));
            dp[i]=mi;
            if(mi==a){
                two++;
            }
            if(mi==b){
                three++;
            }
            if(mi==c){
               five++; 
            }
        }
        return dp[n];
    }
};
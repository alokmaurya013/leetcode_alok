#define mod 1000000007
class Solution {
public:
    int checkRecord(int n) {
        int dp[100001][2][3]={0};
        for(int j=0;j<=1;j++){
            for(int k=0;k<=2;k++){
                dp[0][j][k]=1;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<=1;j++){
                for(int k=0;k<=2;k++){
                    long long res=dp[i-1][j][0];
                    if(j==0){
                        res+=dp[i-1][j+1][0];
                    }
                    if(k<2){
                        res+=dp[i-1][j][k+1];
                    }
                    dp[i][j][k]=res%mod;
                }
            }
        }
        return dp[n][0][0];
    }
};
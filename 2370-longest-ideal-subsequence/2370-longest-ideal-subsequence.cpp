#include<bits/stdc++.h>
class Solution {
public:
    int longestIdealString(string s, int k) {
        int n=s.size(),mx=0;
        vector<int>dp(26,0);
        for(int i=0;i<n;i++){
              int i1=s[i]-'a';
            int j1=max(0,i1-k),j2=min(25,i1+k);
            for(int j=j1;j<=j2;j++){
                dp[i1]=max(dp[i1],dp[j]);
            }
            dp[i1]=dp[i1]+1;
        }
        for(int i=0;i<=25;i++){
            if(mx<dp[i]){
                mx=dp[i];
            }
        }
        return mx;
    }
};
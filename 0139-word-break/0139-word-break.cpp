#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=wordDict.size();
        int m=s.length(),mx=0;
        for(int i=0;i<n;i++){
            int l=wordDict[i].size();
            mx=max(mx,l);
        }
        vector<bool>dp(m+1,false);
        dp[0]=true;
        for(int i=1;i<=m;i++){
            for(int j=i-1;j>=max(i-mx-1,0);j--){
                if(dp[j]&&find(wordDict.begin(),wordDict.end(),s.substr(j,i-j))!=wordDict.end()){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[m];
    }
};
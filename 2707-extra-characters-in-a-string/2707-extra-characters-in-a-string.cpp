class Solution {
public:
    int solve(int i,int n,string &s,vector<int>&dp,unordered_set<string>&st){
        if(i==n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        string curr;
        int mi=n;
        for(int j=i;j<n;j++){
            curr+=s[j];
            int next=solve(j+1,n,s,dp,st);
            int cextra=(st.count(curr))? 0 :curr.size();
            mi=min(mi,cextra+next);
        }
        return dp[i]=mi;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        int n=s.size();
        unordered_set<string>st;
        vector<int>dp(n+1,-1);
        for(auto &t:dictionary){
            st.insert(t);
        }
        return solve(0,n,s,dp,st);
        
    }
};
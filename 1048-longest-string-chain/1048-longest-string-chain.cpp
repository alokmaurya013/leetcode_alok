class Solution {
public:
   
static bool cmp(string&a,string&b){
    return a.size()<b.size();
}
bool isSubsequence(string &a,string &b){
    int i=0,j=0;
    while (i<a.size()&&j<b.size()){
         if(a[i]==b[j]){
            i++;
         }
        j++;
    }
    return (i==a.size());
}
    int longestStrChain(vector<string>& words) {
           sort(words.begin(),words.end(),cmp);
   vector<vector<int>>dp(words.size()+1,vector<int>(words.size()+1,0));
   for(int i=words.size()-1;i>=0;i--){
    for(int j=words.size()-1;j>=-1;j--){
        if(j==-1){
            dp[i][j+1]=max(dp[i+1][j+1],1+dp[i+1][i+1]);
            continue;
        }
        int maxi=0;

        if(words[j].size()==words[i].size()-1&&isSubsequence(words[j],words[i])){
            dp[i][j+1]=1+dp[i+1][i+1];
        }
        dp[i][j+1]=max(dp[i][j+1],dp[i+1][j+1]);
    }
   }
   return dp[0][0];

    }
};
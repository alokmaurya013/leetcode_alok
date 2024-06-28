class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int>in(n,0);
        for(auto e:roads){
           in[e[0]]++;
           in[e[1]]++;
        }
        long long ans=0;
        sort(in.begin(),in.end());
        for(int i=0;i<n;i++){
            ans+=(i+1LL)*in[i];
        }
        return ans;
    }
};
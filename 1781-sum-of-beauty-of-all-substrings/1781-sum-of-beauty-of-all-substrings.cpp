class Solution {
public:
    int beautySum(string s) {
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++){
            unordered_map<int,int>mp;
            for(int j=i;j<n;j++){
              mp[s[j]-'a']++;  
                int mi=INT_MAX;
                int mx=0;
                for(auto it:mp){
                    mx=max(mx,it.second);
                    mi=min(mi,it.second);
                }
                ans+=(mx-mi);
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<string>ans;
    void solve(int i,string &s,string &t,unordered_map<string,bool>&mp){
        if(i>=s.size()){
            ans.push_back(t);
            return;
        }
        for(int j=i+1;j<=s.size()&&j<=i+10;j++){
            string k=s.substr(i,j-i);
            if(mp.find(k)!=mp.end()){
                if(t.size()==0){
                    t=k;
                }else{
                    t+=" "+k;
                }
                solve(j,s,t,mp);
                int x=0;
                while(x<k.size()){
                    x++;
                    t.pop_back();
                }
                if(t.size()>0){
                    t.pop_back();
                }
            }
        }
        
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,bool>mp;
        for(auto t:wordDict){
            mp[t]=true;
        }
        string t="";
        ans.clear();
        solve(0,s,t,mp);
        return ans;
    }
};
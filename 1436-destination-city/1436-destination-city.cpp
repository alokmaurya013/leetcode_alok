class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
      unordered_map<string,string>mp;
        unordered_set<string>s;
        for(auto it:paths){
            s.insert(it[0]);
            s.insert(it[1]);
            mp[it[0]]=it[1];
        }
        string a="";
        for(auto it:s){
            if(mp.find(it)==mp.end()){
                a+=it;
            }
        }
        return a;
    }
};
class Solution {
public:
     unordered_map<string,int>mp;
    void stringMap(string s){
        stringstream ss(s);
        string word;
        while(ss>>word){
            mp[word]++;
        }
    }
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string>res;
       stringMap(s1);
        stringMap(s2);
        for(auto s:mp){
            if(s.second==1){
               res.push_back(s.first); 
            }
        }
        return res;
    }
};
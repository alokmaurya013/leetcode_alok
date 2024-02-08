class Solution {
public:
    string frequencySort(string s) {
        int n=s.size();
        unordered_map<char,int>mp;
        vector<pair<int,char>>v;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        for(auto i:mp){
                v.push_back({i.second,i.first});
        }
        sort(v.rbegin(),v.rend());
        string res="";
        for(auto i:v){
           for(int j=0;j<i.first;j++){
               res+=i.second;
           } 
        }
        return res;
    }
};
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<string,int>mp;
     
        for(auto a:arr1){
         string s=to_string(a);
           string pre="";
            for(auto ch:s){
            pre+=ch;
            mp[pre]++;
            }
        }
        int mx=0;
        for(auto num:arr2){
            string s=to_string(num);
            string pre="";
            for(auto ch:s){
                pre+=ch;
            if(mp.find(pre)!=mp.end()){
                mx=max(mx,static_cast<int>(pre.length()));
            }
            }
        }
        return mx;
    }
};
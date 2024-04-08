class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        // int i=0,j=0;
        // while(i<s.size() && j<t.size()){
        //     if(s[i]!=t[j]) return false;
        //     i++;
        //     j++;
        // }
        // if(i==s.size() && j==t.size()) return true;
        // return false;
        if(s==t){
           return true;
        }return false;
    }
};
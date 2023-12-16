class Solution {
public:
    bool isAnagram(string s, string t) {
        int n=s.size();
        int m=t.size();
        int mp[26]={0};
        if(n!=m){
            return false;
        }
        for(int i=0;i<n;i++){
            mp[s[i]-'a']++;
            mp[t[i]-'a']--;
        }
        for(int i:mp){
            if(i!=0){
                return false;
            }
        }
        return true;
    }
};
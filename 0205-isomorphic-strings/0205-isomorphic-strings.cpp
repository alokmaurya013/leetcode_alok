class Solution {
public:
    bool isIsomorphic(string s, string t) {
       vector<int>a(200,0);
        vector<int>b(200,0);
        int n=s.length();
        if(n!=t.length()){
            return false;
        }
        for(int i=0;i<n;i++){
            if(a[s[i]]!=b[t[i]]){
                return false;
            }
            a[s[i]]=i+1;
            b[t[i]]=i+1;
        }
        return true;
    }
};
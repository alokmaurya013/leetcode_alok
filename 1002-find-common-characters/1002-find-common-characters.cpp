class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int>a(26,0);
        vector<int>b(26,0);
        int n=words.size();
        for(auto i:words[0]){
            a[i-'a']++;
        }
        if(n==1){
            int l=words[0].size();
            vector<string>v;
            string s=to_string(l);
            v.push_back(s);
            return v;
        }
        for(int i=1;i<n;i++){
        for(char ch:words[i]){
            b[ch-'a']++;
        }
        for(int j=0;j<26;j++){
            a[j]=min(a[j],b[j]);
            b[j]=0;
        }
        }
        vector<string>v;
        for(int i=0;i<26;i++){
            int n=a[i];
            for(int j=0;j<n;j++){
                char ch='a';
                v.push_back(string(1,i+ch));
            }
        }
        return v;
    }
};
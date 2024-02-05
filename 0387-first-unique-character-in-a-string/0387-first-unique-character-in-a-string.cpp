class Solution {
public:
    int firstUniqChar(string s) {
        int a[26]={0},b[26];
        int n=s.size();
        for(int i=0;i<n;i++){
            a[s[i]-'a']++;
            b[s[i]-'a']=i;
        }
        int x=INT_MAX;
        for(int i=0;i<26;i++){
            if(a[i]==1){
                x=min(x,b[i]);
            }
        }
        if(x==INT_MAX){
            return -1;
        }else{
            return x;
        }
    }
};
class Solution {
public:
    string customSortString(string order, string s) {
        int a[26]={0};
        int n=s.size(),m=order.size();
        for(int i=0;i<n;i++){
            a[s[i]-'a']++;
        }
        string t="";
        for(int i=0;i<m;i++){
            char ch=order[i];
            int f=a[ch-'a'];
            a[ch-'a']=0;
            for(int i=0;i<f;i++){
                t+=ch;
            }
        }
        for(int i=0;i<26;i++){
            if(a[i]==0){
                continue;
            }
            while(a[i]!=0){
                t+=char(i+'a');
                a[i]--;
            }
        }
        return t;
    }
};
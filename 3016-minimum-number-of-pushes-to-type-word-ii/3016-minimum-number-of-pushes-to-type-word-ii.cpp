class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        int a[26]={0};
        for(int i=0;i<n;i++){
            a[word[i]-'a']++;
        }
        sort(a,a+26,greater<int>());
        int ans=0,c=1;
        for(int i=0;i<26&&a[i]!=0;i++){
            if(i>=8&&i%8==0){
                c++;
            }
            ans+=a[i]*c;
        }
        return ans;
    }
};
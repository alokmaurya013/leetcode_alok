class Solution {
public:
    bool makeEqual(vector<string>& words) {
       int a[26]={0};
        int n=words.size();
        for(int i=0;i<n;i++){
            int m=words[i].length();
            for(int j=0;j<m;j++){
                a[words[i][j]-'a']++;
            }
        }
        for(int j=0;j<26;j++){
            if(a[j]!=0&&a[j]%n!=0){
                return false;
            }
        }
        return true;
    }
};
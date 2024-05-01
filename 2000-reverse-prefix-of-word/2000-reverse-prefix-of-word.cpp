class Solution {
public:
    string reversePrefix(string word, char ch) {
        string s="";
        int n=word.size(),j=-1;
        for(int i=0;i<n;i++){
            s+=word[i];
           if(word[i]==ch){
               j=i;
             break;
           }
        }
        if(j==-1){
            s="";
        }
        reverse(s.begin(),s.end());
        for(int i=j+1;i<n;i++){
            s+=word[i];
        }
        return s;
    }
};
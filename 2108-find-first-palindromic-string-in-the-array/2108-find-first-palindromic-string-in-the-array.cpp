class Solution {
public:
    bool isPalindrome(string &t){
        int n=t.size();
        for(int i=0;i<n/2;i++){
            if(t[i]!=t[n-i-1]){
                return false;
            }
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        int n=words.size();
        string s="";
        for(int i=0;i<n;i++){
            if(isPalindrome(words[i])){
                s=words[i];
                break;
            }
        }
        return s;
    }
};
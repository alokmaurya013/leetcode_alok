class Solution {
public:
    int lengthOfLastWord(string s) {
        int i=s.length()-1;
        while(s[i]==' '){
            i--;
        }
        int temp=i;
        while(i>=0&&s[i]!=' '){
            i--;
        }
        return temp-i;
    }
};
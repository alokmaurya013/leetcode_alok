class Solution {
public:
    int countPalindromicSubsequence(string s) {
         int c=0;
   unordered_set<char>st;
   for(char ch:s){
    st.insert(ch);
   }       
   for(char ch:st){
    int start=s.find(ch);
    int end=s.rfind(ch);
    if(start<end){
      unordered_set<char>cs;
      for(int i=start+1;i<end;i++){
        cs.insert(s[i]);
      }
      c+=cs.size();
    }
   }
   return c;
    }
};
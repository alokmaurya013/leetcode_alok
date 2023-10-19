class Solution {
public:
    int solve(string &str){
   int i=0;
   for(char c:str){
     if(c!='#'){
        str[i++]=c;
     }else if(i>0){
        i--;
     }
   }
   return i;
}
    bool backspaceCompare(string s, string t) {
  int  m=solve(s);
  int n=solve(t);
  if(m!=n){
    return false;
  }
  for(int i=0;i<n;i++){
    if(s[i]!=t[i]){
      return false;
    }
  }
  return true;
    }
};
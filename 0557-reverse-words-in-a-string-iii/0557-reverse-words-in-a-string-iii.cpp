class Solution {
public:
    string reverseWords(string s) {
       int n=s.length();
   int i=0;
   string u="",t="";
   while (i<n){
     if(s[i]==' ')
     {
       reverse(t.begin(),t.end());
       u+=t;
    u+=' ';
       t="";
       i++;
     }else{
        t+=s[i];
        i++;
     }
   }
        reverse(t.begin(),t.end());
        u+=t;
   return u; 
    }
};
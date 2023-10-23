class Solution {
public:
    string reverseWords(string s) {
        vector<string>v;
        int n=s.size();
   int i=0;
   string t;
   while (i<n){
     if(s[i]!=' '){
      t+=s[i];
     }else if(s[i]==' '&&t!=""){
        v.push_back(t);
        v.push_back(" ");
        t="";
     }
     i++;
   }
   if(s[n-1]==' '){
    v.pop_back();
   }else{
    v.push_back(t);
   }
   reverse(v.begin(),v.end());
   string a;
        int m=v.size();
   for(int i=0;i<m;i++){
       a+=v[i];
   }
        return a;
    }
};
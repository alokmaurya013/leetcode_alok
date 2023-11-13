class Solution {
public:
   set<int>st={'a','e','i','o','u','A','E','I','O','U'};
    string sortVowels(string s) {
      string t="";
    int n=s.size();
    for(int i=0;i<n;i++){
      if(st.find(s[i])!=st.end()){
        t+=s[i];
      }
    } 
    sort(t.begin(),t.end());
    int j=0;
    for(int i=0;i<n;i++){
      if(st.find(s[i])!=st.end()){
         s[i]=t[j++];
      }
    }
    return s;   
    }
};
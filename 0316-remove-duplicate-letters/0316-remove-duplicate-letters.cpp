class Solution {
public:
   string removeDuplicateLetters(string s) {
           int n=s.size();
    int end[26]={0};
    for(int i=0;i<n;i++){
        end[s[i]-'a']=i;
    }
    int see[26]={0};
    string st="";
    for(int i=0;i<n;i++){
        while (st.size()&&(st.back()>s[i])&&(end[st.back()-'a']>i)&&(see[s[i]-'a']==0)){
            see[st.back()-'a']=0;
            st.pop_back();
        }
        if(see[s[i]-'a']==0){
            st.push_back(s[i]);
            see[s[i]-'a']=1;
        }
    }
    return st; 
    } 
};
class Solution {
public:
    string reverseParentheses(string s) {
       stack<int>st;
        int i=0,n=s.size();
        while(i<n){
            if(s[i]=='('){
                st.push(i);
            }else if(s[i]==')'){
               reverse(s.begin()+st.top(),s.begin()+i);
                st.pop();
            }
            i++;
        }
      s.erase(remove(s.begin(),s.end(),')'),s.end());
      s.erase(remove(s.begin(),s.end(),'('),s.end());
       
        return s;
    }
};
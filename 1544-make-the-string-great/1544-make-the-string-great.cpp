class Solution {
public:
  
    string makeGood(string s) {
        int n=s.length(),isupper=0;
        for(int i=0;i<n;i++){
            if(s[i]>='A'&&s[i]<='Z'){
                isupper=1;
                break;
            }
        }
        if(n==1||isupper==0){
            return s;
        }
        stack<char>st;
        int i=0;
        st.push(s[i]);
        i++;
        while(i<n){
            if(st.empty()){
                st.push(s[i]);
            }else{
            char t=st.top();
        
            if(t>='a'&&t<='z'){
                if(t==s[i]-'A'+'a'){
                    st.pop();
                }else{
                    st.push(s[i]);
                }
            }else{
                if(t==(s[i]-'a'+'A')){
                    st.pop();
                }else{
                    st.push(s[i]);
                }
            }
            }
            i++;
        }
        string t="";
        while(!st.empty()){
            t+=st.top();
            st.pop();
        }
        reverse(t.begin(),t.end());
        return t;
    }
};
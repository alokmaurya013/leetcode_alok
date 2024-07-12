class Solution {
public:
    int solve(string &s,string p){
        stack<char>st;
        int cnt=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(!st.empty()&&st.top()==p[0]&&s[i]==p[1]){
                st.pop();
                cnt++;
            }else{
                st.push(s[i]);
            }
        }
        s="";
        while(!st.empty()){
            s+=st.top();
            st.pop();
        }
        reverse(s.begin(),s.end());
        return cnt;
    }
    int maximumGain(string s, int x, int y) {
       string a="",b="";
       if(y>x){
           a="ba";
           b="ab";
           swap(x,y);
       }else{
           a="ab";
           b="ba";
       }
        int c=solve(s,a)*x;
        int d=solve(s,b)*y;
        return c+d;
    }
};
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        int n=ast.size();
        stack<int>st;
        for(int i=0;i<n;i++){
            bool flag=true;
            while(!st.empty()&&ast[i]<0&&st.top()>0){
                if(st.top()==abs(ast[i])){
                    st.pop();
                }else if(st.top()<abs(ast[i])){
                    st.pop();
                    continue;
                }
                flag=false;
                break;
            }
            if(flag){
                st.push(ast[i]);
            }
        }
        vector<int>v(st.size());
        for(int i=st.size()-1;i>=0;i--){
            v[i]=st.top();
            st.pop();
        }
        return v;
    }
};
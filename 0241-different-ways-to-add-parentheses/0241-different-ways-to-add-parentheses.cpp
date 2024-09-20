class Solution {
public:
    unordered_map<string,vector<int>>mp;   
    
    vector<int>solve(string s){
        int n=s.size();
        vector<int>v;
        if(mp.find(s)!=mp.end()){
            return mp[s];
        }
        for(int i=0;i<s.size();i++){
            if(s[i]=='+'||s[i]=='-'||s[i]=='*'){
                vector<int>left=solve(s.substr(0,i));
                vector<int>right=solve(s.substr(i+1));
                
                for(auto l:left){
                    for(auto r:right){
                        if(s[i]=='+'){
                            v.push_back(l+r);
                        }else if(s[i]=='-'){
                            v.push_back(l-r);
                        }else{
                            v.push_back(l*r);
                        }
                    }
                }
            }
           
        }
         if(v.empty()){
                v.push_back(stoi(s));
            }
        return mp[s]=v;
    }
    vector<int> diffWaysToCompute(string expression) {
       return solve(expression);
    }
};
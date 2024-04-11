class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size();
        vector<char>v;
        for(auto i:num){
            while(k>0&&!v.empty()&&v.back()>i){
                v.pop_back();
                k--;
            }
             v.push_back(i);
        }
            while(k>0){
                v.pop_back();
                k--;
            }
        string t="";
         for(auto i:v){
                if(t.empty() && i=='0'){
                    continue;
                }
                t+=i;
            }
        if(t.size()==0){
            return "0";
        }
        return t;
    }
};
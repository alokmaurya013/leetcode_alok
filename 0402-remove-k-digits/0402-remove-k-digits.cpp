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
        num="";
         for(auto i:v){
                if(num.empty() && i=='0'){
                    continue;
                }
                num+=i;
            }
        if(num.size()==0){
            return "0";
        }
        return num;
    }
};
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string>tmp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            tmp.push_back(to_string(nums[i]));
        }
        sort(tmp.begin(),tmp.end(),[](const string &a,const string &b){
            return (b+a)<(a+b);
        });
        string t="";
        for(string s:tmp){
            t+=s;
        }
        if(tmp[0]=="0"){
            return "0";
        }
        return t;
    }
};
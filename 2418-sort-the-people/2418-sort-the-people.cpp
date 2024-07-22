class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int,int>>a;
        int n=names.size();
        for(int i=0;i<n;i++){
            a.push_back({heights[i],i});
        }
        sort(a.rbegin(),a.rend());
        vector<string>s;
        for(auto i:a){
            
            s.push_back(names[i.second]);
        }
        return s;
    }
};
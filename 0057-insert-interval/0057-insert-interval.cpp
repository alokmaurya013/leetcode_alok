class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n=intervals.size(),a=newInterval[0],b=newInterval[1];
        vector<vector<int>>ans;
      
        for(auto i:intervals){
            if(i[1]<a){
                 ans.push_back(i);   
            }else if(i[0]>b){
                ans.push_back({a,b});
                a=i[0];
                b=i[1];
            }else{
                a=min(a,i[0]);
                b=max(b,i[1]);
            }
            
        }
        ans.push_back({a,b});
        return ans;
    }
};
class Solution {
public:
    bool cmp(const vector<int>&d,const vector<int>&e){
        if(d[0]==e[0]){
            return d[1]<e[1];
        }
        return d[0]<e[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>v;
        sort(intervals.begin(),intervals.end(),[&](const auto& a, const auto& b) {
           if(a[0]==b[0]){
               return a[1]<b[1];
           }
            return a[0]<b[0];
        });
        int a=intervals[0][0],b=intervals[0][1];
        int n=intervals.size();
        for(int i=1;i<n;i++){
           if(intervals[i][0]>=a&&intervals[i][0]<=b){
               b=max(b,intervals[i][1]);
           }else{
               v.push_back({a,b});
               a=intervals[i][0];
               b=intervals[i][1];
           } 
        }
        v.push_back({a,b});
        return v;
    }
};
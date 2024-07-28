class Solution {
public:
    bool static cmp(vector<int>&a,vector<int>&b){
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        int n=intervals.size();
        int a=intervals[0][1];
        int c=1;
        for(int i=1;i<n;i++){
            if(intervals[i][0]>=a){
                c++;
                a=intervals[i][1];
            }
        }
        return n-c;
    }
};
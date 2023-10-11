class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int n=people.size();
        int m=flowers.size();
        vector<int>ans(n),start(m),end(m);
        for(int i=0;i<m;i++){
            start[i]=flowers[i][0];
            end[i]=flowers[i][1];
        }
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        for(int i=0;i<n;i++){
            int x=people[i];
            int s=upper_bound(start.begin(),start.end(),x)-start.begin();
            int e=lower_bound(end.begin(),end.end(),x)-end.begin();
            cout<<s<<" "<<e<<endl;
            ans[i]=s-e;
        }
        return ans;
    }
};
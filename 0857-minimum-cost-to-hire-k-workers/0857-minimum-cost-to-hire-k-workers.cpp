class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        vector<pair<double,int>>v;
        int n=quality.size();
        double mi=INT_MAX;
        int curr=0;
        priority_queue<int>pq;
        for(int i=0;i<n;i++){
            v.push_back({static_cast<double>(wage[i])/quality[i],quality[i]});
        }
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++){
            double rt=v[i].first;
            int qu=v[i].second;
            pq.push(qu);
            curr+=qu;
            if(pq.size()>k){
                curr-=pq.top();
                pq.pop();
            }
            if(pq.size()==k){
                mi=min(mi,curr*rt);
            }
        }
        return mi;
    }
};
class Solution {
public:
    
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
       auto cmp=[&arr](pair<int,int>&a,pair<int,int>&b){
           return arr[a.first]*arr[b.second]>arr[b.first]*arr[a.second];
       };
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)>pq(cmp);
        int n=arr.size();
        for(int i=0;i<n-1;i++){
            pq.push({i,n-1});
        }
        for(int i=1;i<k;i++){
            auto t=pq.top();
            pq.pop();
            int ni=t.first;
            int nj=t.second;
            if(nj-1>ni){
                pq.push({ni,nj-1});
            }
        }
        return {arr[pq.top().first],arr[pq.top().second]};
    }
};
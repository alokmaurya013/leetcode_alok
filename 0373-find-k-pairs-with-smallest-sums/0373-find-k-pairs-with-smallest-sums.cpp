class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
     
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<vector<int>>ans;
        for(int a:nums1){
            pq.push({a+nums2[0],0});
        }
        int c=0;
        while(!pq.empty()&&c<k){
            int sum=pq.top().first;
            int ind=pq.top().second;
            pq.pop();
            ans.push_back({sum-nums2[ind],nums2[ind]});
            
            if(ind+1<nums2.size()){
                pq.push({sum-nums2[ind]+nums2[ind+1],ind+1});
            }
            c++;
        }
        return ans;
    }
};
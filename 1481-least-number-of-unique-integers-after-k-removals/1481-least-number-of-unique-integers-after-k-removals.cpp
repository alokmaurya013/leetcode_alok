class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        vector<pair<int,int>>v;
        unordered_map<int,int>mp;
        int n=arr.size();
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        for(auto i:mp){
            v.push_back({i.second,i.first});
        }
       sort(v.begin(),v.end());
       int i=0;
        int c=v.size();
        while(k>0){
            if(v[i].first>k){
               v[i].first-=k;
                k=0;
            }else{
                k-=v[i].first;
                i++;
                c--;
            }
        }
        return c;
    }
};
class Solution {
public:
    static bool cmp(pair<int,int>a,pair<int,int>b){
        if(a.first==b.first){
            return a.second>b.second;
        }
        return a.first<b.first;
    }
    vector<int> frequencySort(vector<int>& nums) {
        vector<int>res;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int c=1;
        vector<pair<int,int>>v;
        for(int i=n-2;i>=0;i--){
            if(nums[i]==nums[i+1]){
                c++;
            }else{
                v.push_back({c,nums[i+1]});
                c=1;
            }
        }
        v.push_back({c,nums[0]});
        sort(v.begin(),v.end(),cmp);
        for(auto t:v){
            int m=t.first;
            int a=t.second;
            while(m){
                res.push_back(a);
                m--;
            }
        }
        return res;
    }
};
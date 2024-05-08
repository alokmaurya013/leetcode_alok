class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<pair<int,int>>v;
        int n=score.size();
        for(int i=0;i<n;i++){
             v.push_back({score[i],i});
        }
        sort(v.begin(),v.end());
        vector<string>s(n,"");
        for(int i=n-1;i>=0;i--){
            if(i==n-1){
                s[v[i].second]="Gold Medal";
            }else if(i==n-2){
                s[v[i].second]="Silver Medal";
            }else if(i==n-3){
                s[v[i].second]="Bronze Medal";
            }else{
                s[v[i].second]=to_string(n-i);
            }
        }
        return s;
    }
};
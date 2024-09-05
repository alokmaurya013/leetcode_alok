class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m=rolls.size();
        int avg=mean*(m+n);
        int need=avg;
        for(int i=0;i<m;i++){
            need-=rolls[i];
        }
        cout<<avg<<" "<<need<<" ";
        vector<int>ans;
        if(need<n||need>n*6){
            return ans;
        }else{
            int f=need/n;
            int extra=need%n;
            cout<<f<<" "<<extra<<" ";
            for(int i=0;i<n;i++){
                if(extra>0){
                    ans.push_back(f+1);
                }else{
                    ans.push_back(f);
                }
                extra=max(extra-1,0);
            }
        }
        return ans;
    }
};
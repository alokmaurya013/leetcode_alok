class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n=dist.size();
        int c=1;
        vector<int>cnt;
        for(int i=0;i<n;i++){
            int t=(dist[i]%speed[i]==0)?0:1;
            t+=dist[i]/speed[i];
            cnt.push_back(t);
        }
        sort(cnt.begin(),cnt.end());
        for(int i=1;i<n;i++){
            int k=cnt[i]-c;
            if(k<=0){
               break; 
            }
            c++;
        }
        return c;
    }
};
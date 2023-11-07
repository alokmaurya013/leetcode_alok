class Solution {
public:
    priority_queue<int,vector<int>,greater<int>>pq;
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n=dist.size();
         for(int i=0;i<n;i++){
             int t=(dist[i]%speed[i]!=0?1:0);
             t+=dist[i]/speed[i];
             pq.push(t);
         }
        int c=0;
        while(!pq.empty()){
            int t=pq.top();
            c++;
            pq.pop();
            int k=pq.top()-c;
            if(k<=0){
               break; 
            }
        }
        return c;
    }
};
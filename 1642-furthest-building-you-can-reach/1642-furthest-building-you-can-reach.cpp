class Solution {
public:
    int furthestBuilding(vector<int>& h, int bricks, int ladders) {
        priority_queue<long long>pq;
        int n=h.size();
        for(int i=0;i<n-1;i++){
            int d=h[i+1]-h[i];
            if(d>0){
               bricks-=d;
                pq.push(d);
            }
                if(bricks<0){
                    if(ladders>0){
                        bricks+=pq.top();
                        pq.pop();
                        ladders--;
                    }else{
                        return i;
                    }
            }
        }
        return n-1;
        
    }
};
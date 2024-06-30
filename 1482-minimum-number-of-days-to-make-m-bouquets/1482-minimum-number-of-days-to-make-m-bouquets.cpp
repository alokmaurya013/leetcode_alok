class Solution {
public:
    bool possible(vector<int>&b,int m,int k,int mid){
         int key=0,cnt=0;
        int n=b.size();
        for(int i=0;i<n;i++){
            if(b[i]<=mid){
                cnt++;
            }else{
                key+=(cnt/k);
                cnt=0;
            }
        }
        key+=(cnt/k);
        return key>=m;
    }
    int minDays(vector<int>& b, int m, int k) {
        int mi=INT_MAX;
        int mx=INT_MIN;
        int n=b.size();
        for(int i=0;i<n;i++){
            mi=min(mi,b[i]);
            mx=max(mx,b[i]);
        }
        if((long long)m*k >n){
            return -1;
        } 
        int low=mi,high=mx;
        while(low<=high){
            int mid=(low+high)/2;
            if(possible(b,m,k,mid)){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};
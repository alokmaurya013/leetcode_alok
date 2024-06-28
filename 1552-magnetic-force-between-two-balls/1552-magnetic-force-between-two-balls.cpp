class Solution {
public:
    bool isPossible(vector<int>&position,int m,int mid){
        int last=position[0];
        int n=position.size();
        int c=1;
        for(int i=1;i<n;i++){
            if(position[i]-last>=mid){
                last=position[i];
                c++;
            }
            if(c==m){
                return true;
            }
        }
        return false;
        
    }
    int maxDistance(vector<int>& position, int m) {
        int n=position.size();
        sort(position.begin(),position.end());
        int ans=1,s=1,e=(position[n-1]-position[0])/(m-1);
         while(s<=e){
            int mid=(s+e)/2;
             if(isPossible(position,m,mid)){
                 ans=mid;
                 s=mid+1;
             }else{
                 e=mid-1;
             }
         }
        return ans;
    }
};
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int c=0,n=arr.size();
        for(int i=0;i<n;i++){
            int v=arr[i];
            for(int k=i+1;k<n;k++){
                v^=arr[k];
                if(v==0){
                    c+=(k-i);
                }
            }
        }
        return c;
    }
};
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n=arr.size();
        int a=0,m=n/4;
        for(int i=0;i<n;i++){
            if(arr[i]==arr[i+m]){
                a=arr[i];
                break;
            }
        }
        return a;
    }
};
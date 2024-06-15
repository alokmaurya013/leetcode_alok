class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int n=arr1.size(),m=arr2.size();
        unordered_map<int,int>mp;
        for(int i=0;i<m;i++){
            mp[arr2[i]]=0;
        }
        for(int i=0;i<n;i++){
            if(mp.find(arr1[i])!=mp.end()){
                mp[arr1[i]]++;
                arr1[i]=0;
            }
        }
        sort(arr1.begin(),arr1.end());
        int j=0;
        for(int i=0;i<m;i++){
            int c=mp[arr2[i]];
            while(c){
                arr1[j++]=arr2[i];
                c--;
            }
        }
        return arr1;
    }
};
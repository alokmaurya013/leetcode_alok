class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int>in(n+2,0);
        for(auto e:edges){
           // cout<<e[0]<<" "<<e[1]<<endl;
            in[e[0]]++;
            in[e[1]]++;
        }
        for(int i=1;i<=n+1;i++){
            if(in[i]==n){
                return i;
            }
        }
        return 0;
    }
};
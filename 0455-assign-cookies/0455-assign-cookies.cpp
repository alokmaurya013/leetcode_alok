class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int m=s.size(),n=g.size();
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int mx,c=0;
        if(m!=0){
            mx=s[m-1];
        }
        int i=0,j=0;
        while(i<n&&j<m){
            if(g[i]<=s[j]){
                i++;
                j++;
                c++;
            }else{
                j++;
            }
        }
        return c;
    }
};
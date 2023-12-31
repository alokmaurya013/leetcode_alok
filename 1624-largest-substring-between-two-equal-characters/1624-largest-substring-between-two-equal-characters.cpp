class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n=s.size(),ans=0,flag=0;
        vector<int>v(26,-1);
        for(int j=0;j<n;j++){
            if(v[s[j]-'a']==-1){
                v[s[j]-'a']=j;
              //  cout<<j<<endl;
            }else{
               ans=max(ans,j-v[s[j]-'a']-1);
              //  cout<<j<<" "<<v[s[j]-'a']<<endl;
                flag=1;
            }
        }
        if(flag==0){
            return -1;
        }else{
            return ans;
        }
    }
};
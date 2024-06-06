class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
      map<int,int>mp;
        for(auto i:hand){
            mp[i]++;
        }
        int n=hand.size(),m=mp.size();
        if(n%groupSize!=0){
            return false;
        }
        vector<int>a;
        for(auto i:mp){
            a.push_back(i.first);
        }
        int flag=1;
        for(int i=0;i<=m-groupSize;i++){
            int c=mp[a[i]];
            if(c!=0){
             mp[a[i]]=0;
            for(int j=i+1;j<i+groupSize;j++){
                if(a[j]==a[j-1]+1&&mp[a[j]]>=c){
                    mp[a[j]]-=c;
                }else{
                    flag=0;
                    break;
                }
            }
            }
        }
        if(flag==0){
            return 0;
        }
        for(int i=0;i<m;i++){
            if(mp[a[i]]!=0){
                flag=0;
                break;
            }
        }
        return flag;
    }
};
class Solution {
public:

    int openLock(vector<string>& deadends, string target) {
      vector<int>vis(10000,0);
       int n=deadends.size();
        queue<pair<int,string>>q;
        for(auto i:deadends){
            vis[stoi(i)]=1;
        }
        if(vis[0]){
            return -1;
        }
        //q.emplace(0,"0000");
        q.push({0,"0000"});
        vis[0]=1;
        while(!q.empty()){
            auto [turn,s]=q.front();
            q.pop();

            if(s==target){
                return turn;
            }
            for(int i=0;i<4;i++){
                for(auto j:{-1,1}){
                    string t=s;
                    char& ch=t[i];
                    ch=(ch-'0'+j+10)%10+'0';
                    int tmp=stoi(t);
                    if(!vis[tmp]){
                        vis[tmp]=1;
                        q.push({turn+1,t});
                    }
                }
            }
        }
        return -1;
    }
};
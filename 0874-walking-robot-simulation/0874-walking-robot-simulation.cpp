class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_map<string,int>mp;
        for(auto it:obstacles){
            string key=to_string(it[0])+"+"+to_string(it[1]);
            mp[key]++;
        }
        int mx=0;
        int dir=1,x=0,y=0;
        vector<vector<int>>dx={{-1,0},{0,1},{1,0},{0,-1}};
        for(auto it:commands){
            if(it==-2){
            if(dir==0){
                dir=3;
            }else{
                dir--;
            }
            }else if(it==-1){
                dir=(dir+1)%4;
            }else{
                int k=it;
                int nx,ny;
                for(int i=1;i<=k;i++){
                    nx=x+dx[dir][0];
                    ny=y+dx[dir][1];
                    string t=to_string(nx)+"+"+to_string(ny);
                    if(mp.find(t)!=mp.end()){
                        break;
                    }
                    x=nx;
                    y=ny;
                    mx=max(mx,x*x+y*y);
                }
            }
        }
        return mx;
    }
};
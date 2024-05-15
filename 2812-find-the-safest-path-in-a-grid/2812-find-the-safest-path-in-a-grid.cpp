class Solution {
public:
    bool isSafe(vector<vector<int>>&safety,int lim){
        if(safety[0][0]<lim){
            return false;
        }
        queue<pair<int,int>>q;
        q.push({0,0});
        int n=safety.size();
        vector<vector<bool>>vis(n,vector<bool>(n,0));
        vis[0][0]=1;
        while(!q.empty()){
            pair<int,int>p=q.front();
            q.pop();
            int x=p.first;
            int y=p.second;
            if(x==n-1&&y==n-1){return true;}
            if(x+1<n){
                if(!vis[x+1][y]&&safety[x+1][y]>=lim){
                    vis[x+1][y]=1;
                    q.push({x+1,y});
                }
            }
             if(y+1<n){
                if(!vis[x][y+1]&&safety[x][y+1]>=lim){
                    vis[x][y+1]=1;
                    q.push({x,y+1});
                }
            }
             if(x-1>=0){
                if(!vis[x-1][y]&&safety[x-1][y]>=lim){
                    vis[x-1][y]=1;
                    q.push({x-1,y});
                }
            }
             if(y-1>=0){
                if(!vis[x][y-1]&&safety[x][y-1]>=lim){
                    vis[x][y-1]=1;
                    q.push({x,y-1});
                }
            }
        }
        return false;
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>safety(n,vector<int>(n,INT_MAX));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                q.push({{i,j},0});
                   safety[i][j]=0;
            }
            }
        }
        int mx=0;
        while(!q.empty()){
            pair<pair<int,int>,int>t=q.front();
            q.pop();
            int x=t.first.first;
            int y=t.first.second;
            int val=t.second;
            mx=max(mx,val);
            if(x+1<n){
                if(safety[x+1][y]>val+1){
                    safety[x+1][y]=val+1;
                    q.push({{x+1,y},val+1});
                }
            }
            if(y+1<n){
                if(safety[x][y+1]>val+1){
                    safety[x][y+1]=val+1;
                    q.push({{x,y+1},val+1});
                }
            }if(x-1>=0){
                if(safety[x-1][y]>val+1){
                    safety[x-1][y]=val+1;
                    q.push({{x-1,y},val+1});
                }
            }if(y-1>=0){
                if(safety[x][y-1]>val+1){
                    safety[x][y-1]=val+1;
                    q.push({{x,y-1},val+1});
                }
            }
        }
        int start=0,end=mx,mid=(start+end)/2;
        int ans=0;
        while(start<=end){
            if(isSafe(safety,mid)){
                ans=max(ans,mid);
                start=mid+1;
            }else{
                end=mid-1;
            }
            mid=(start+end)/2;
        }
        return ans;
    }
};
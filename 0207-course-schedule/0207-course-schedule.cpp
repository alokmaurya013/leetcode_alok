class Solution {
public:
   //bfs
    bool bfs(int numCourses,vector<vector<int>>&adj){
          vector<int>indegree(numCourses,0);
        for(int i=0;i<numCourses;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        int cnt=0;
        while(!q.empty()){
            int t=q.front();
            q.pop();
            cnt++;
            for(auto it:adj[t]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }

        }
        if(cnt==numCourses){
           return true;
        }else{
            return false;
        }
    }
    bool bfs2(vector<vector<int>>&adj,int i,vector<int>&vis){
        vis[i]=1;
        queue<pair<int,int>>q;
        q.push({i,-1});
        while(!q.empty()){
            int j=q.front().first;
            int pr=q.front().second;
            q.pop();
            for(auto v:adj[j]){
                if(!vis[v]){
                    vis[v]=1;
                    q.push({v,j});
                }else if(v!=pr){
                    return true;
                }
            }
        }
        return false;
    }
        bool undirectedBFS(int numCourses,vector<vector<int>>&adj){
        vector<int>vis(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(bfs2(adj,i,vis)==true){
                    return true;
                }
            }
        }
        return false;
    }
    bool dfs1(vector<vector<int>>&adj,int i,vector<int>&vis,int pr){
        vis[i]=1;
        for(auto j:adj[i]){
            if(!vis[j]){
                if(dfs1(adj,j,vis,i)==true){
                return true;
                }
            }else if(j!=pr){
                return true;
            }
        }
        return false;
    }

    bool undirectedDFS(int numCourses,vector<vector<int>>&adj){
        vector<int>vis(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(dfs1(adj,i,vis,-1)==true){
                    return true;
                }
            }
        }
        return false;
    }
    bool isCyclic(int i,vector<vector<int>>&adj,vector<bool>&vis,vector<bool>&st){
        if(vis[i]==false){
            vis[i]=true;
            st[i]=true;
            for(auto j:adj[i]){
                if(!vis[j]&&isCyclic(j,adj,vis,st)){
                    return true;
                }else if(st[j]){
                    return true;
                }
            }
        }
        st[i]=false;
        return false;
    }
    bool directdfs(int numCourses,vector<vector<int>>&adj){
        vector<bool>vis(numCourses,false);
        vector<bool>st(numCourses,false);
        for(int i=0;i<numCourses;i++){
            if(!vis[i]&&isCyclic(i,adj,vis,st)){
                return false;
            }
        }
        return true;
    }
    bool directed(int numCourses,vector<vector<int>>&prerequisites){
                int n=prerequisites.size();
        vector<vector<int>>adj(numCourses);
        for(auto e:prerequisites){
            adj[e[1]].push_back(e[0]);
        }
       return directdfs(numCourses,adj);   
    }
     bool undirected(int numCourses,vector<vector<int>>&prerequisites){
                int n=prerequisites.size();
        vector<vector<int>>adj(numCourses);
        for(auto e:prerequisites){
            adj[e[1]].push_back(e[0]);
            adj[e[0]].push_back(e[1]);
        }
       return undirectedDFS(numCourses,adj);   
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
       return directed(numCourses,prerequisites);
    }
};
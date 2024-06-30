class DisjointSet{
    vector<int>parent,size;
    public:
     DisjointSet(int n){
         parent.resize(n+1);
         size.resize(n+1);
         for(int i=0;i<=n;i++){
             parent[i]=i;
             size[i]=1;
         }  
     } 
    int findParent(int u){
        if(u==parent[u]){
            return u;
        }
        return parent[u]=findParent(parent[u]);
    }
    bool unionBySize(int u,int v){
        int p_u=findParent(u);
        int p_v=findParent(v);
        if(p_u==p_v){
            return false;
        }
        if(size[p_u]<size[p_v]){
            parent[p_u]=p_v;
            size[p_u]+=size[p_v];
        }else{
            parent[p_v]=p_u;
            size[p_v]+=size[p_u];
        }
        return true;
    }
};
class Solution {
public:
    
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        sort(edges.begin(),edges.end(),[&](auto const &a,auto const &b){
            return a[0]>b[0];
        });
        DisjointSet dsAlice(n+1);
        DisjointSet dsBob(n+1);
        int alice=0,bob=0,remove=0;
        for(auto e:edges){
            if(e[0]==3){
                if(dsAlice.unionBySize(e[1],e[2])){
                    dsBob.unionBySize(e[1],e[2]);
                    alice++;
                    bob++;
                }else{
                    remove++;
                }
            }else if(e[0]==2){
                if(dsAlice.unionBySize(e[1],e[2])){
                   alice++; 
                }else{
                    remove++;
                }
            }else{
                if(dsBob.unionBySize(e[1],e[2])){
                    bob++;
                }else{
                    remove++;
                }
            }
        }
        return (alice==n-1&&bob==n-1)?remove:-1;
    }
};
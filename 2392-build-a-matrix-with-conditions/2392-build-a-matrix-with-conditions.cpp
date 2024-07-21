class Solution {
public:
    vector<int>topoSort(int k,vector<vector<int>>&condition){
        vector<vector<int>>graph(k+1);
        vector<int>indegree(k+1,0);
        for(auto i:condition){
            graph[i[0]].push_back(i[1]);
            indegree[i[1]]++;
        }
        queue<int>q;
        for(int i=1;i<=k;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int>ans;
        while(!q.empty()){
            int t=q.front();
            q.pop();
            ans.push_back(t);
            for(auto v:graph[t]){
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                }
            }
        }
        if(ans.size()!=k){
            return {};
        }
        return ans;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int>rowOrder=topoSort(k,rowConditions);
        vector<int>colOrder=topoSort(k,colConditions);
        if(rowOrder.empty()||colOrder.empty()){
            return {};
        }
        unordered_map<int,int>rowPos,colPos;
        for(int i=0;i<k;i++){
            rowPos[rowOrder[i]]=i;
            colPos[colOrder[i]]=i;
        }
        vector<vector<int>>res(k,vector<int>(k,0));
        for(int i=1;i<=k;i++){
            int r=rowPos[i];
            int c=colPos[i];
            res[r][c]=i;
        }
        return res;
    }
};
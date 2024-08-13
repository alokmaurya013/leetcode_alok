class Solution {
public:
      vector<vector<int>>res;
    void solve(vector<int>&candidates,int i,int j,vector<int>v,int target){
        if(target<0){
            return ;
        }
    if(target==0){
		res.push_back(v);
		return;
	}
    for(int k=i;k<=j;k++){
        if(k>i&&candidates[k]==candidates[k-1]){
            continue;
        }
         if (candidates[k] > target) {
                break; 
            }
        v.push_back(candidates[k]);
	solve(candidates,k+1,j,v,target-candidates[k]);
    v.pop_back();
    }
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    int n=candidates.size();
    vector<int>v;
    sort(candidates.begin(),candidates.end());
    solve(candidates,0,n-1,v,target);
  
    v.clear();
   
	return res;  
    }
};
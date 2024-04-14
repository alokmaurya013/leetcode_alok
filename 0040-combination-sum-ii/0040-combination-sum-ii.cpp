class Solution {
public:
      vector<vector<int>>res;
   // set<vector<int>>s;
    void solve(vector<int>&candidates,int i,int j,vector<int>v,int target,int sum){
    if(target==sum){
		res.push_back(v);
		return;
	}
    if(sum>target){
         return;
    }   
    if(i>j){
        return;
    }
    for(int k=i;k<=j;k++){
        if(k>i&&candidates[k]==candidates[k-1]){
            continue;
        }
        if(candidates[k]>target){
            break;
        }
    v.push_back(candidates[k]);
	solve(candidates,k+1,j,v,target,sum+candidates[k]);
    v.pop_back();
    }

	//solve(candidates,i+1,j,v,target,sum);
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    int n=candidates.size(),sum=0;
    vector<int>v;
    sort(candidates.begin(),candidates.end());
    solve(candidates,0,n-1,v,target,sum);
  
    v.clear();
    // for(auto i:s){
    //     res.push_back(i);
    // }
    // s.clear();
	return res;  
    }
};
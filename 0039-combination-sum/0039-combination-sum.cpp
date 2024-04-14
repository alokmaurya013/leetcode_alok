class Solution {
public:
    vector<vector<int>>res;
    set<vector<int>>s;
    void solve(vector<int>&candidates,int i,int j,vector<int>v,int target,int sum){
    if(target==sum){
        sort(v.begin(),v.end());
		s.insert(v);
		return;
	}
     if(sum>target){
         return;
     }   
    if(i>j){
        return;
    }
    v.push_back(candidates[i]);
	solve(candidates,i,j,v,target,sum+candidates[i]);
        v.pop_back();
	solve(candidates,i+1,j,v,target,sum);
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    int n=candidates.size(),sum=0;
    vector<int>v;
    solve(candidates,0,n-1,v,target,sum);
    for(auto i:s){
        res.push_back(i);
    }
	return res;  
    }
};
class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
         deque<int>dq;
    int s=INT_MIN;
    for(int i=0;i<nums.size();i++){
      if(!dq.empty()){
        nums[i]+=dq.front();
      }
      s=max(s,nums[i]);
      while (!dq.empty()&&dq.back()<nums[i]){
         dq.pop_back();
      }
      if(nums[i]>0){
        dq.push_back(nums[i]);
      }
      if(i>=k&&dq.front()==nums[i-k]&&!dq.empty()){
           dq.pop_front();
      }
    }
    return s; 
    }
};
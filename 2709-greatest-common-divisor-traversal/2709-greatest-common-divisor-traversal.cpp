class Solution {
public:
    int getf(vector<int>&f,int x){
    return f[x]==x?x:(f[x]=getf(f,f[x]));
}
void merge(vector<int>&f,vector<int>&num,int x,int y){
  x=getf(f,x);
  y=getf(f,y);
  if(x==y){
    return;
  }
  if(num[x]<num[y]){
    swap (x,y);
  }
  f[y]=x;
  num[x]+=num[y];
}
    bool canTraverseAllPairs(vector<int>& nums) {
       int n=nums.size();
  if(n==1){
    return true;
  }
  vector<int>f(n),num(n);
  for(int i=0;i<n;i++){
    f[i]=i;
    num[i]=1;
  }
  unordered_map<int,int>mp;
  for(int i=0;i<n;i++){
    int x=nums[i];
    if(x==1){
      return false;
    }
    for(int d=2;d*d<=x;d++){
       if(x%d==0){
        if(mp.count(d)){
          merge(f,num,i,mp[d]);
        }else{
          mp[d]=i;
        }
        while(x%d==0){
          x/=d;
        }
        }
    }
    if(x>1){
      if(mp.count(x)){
        merge(f,num,i,mp[x]);
      }else{
        mp[x]=i;
      }
    }
  }
  return num[getf(f,0)]==n;
    }
};
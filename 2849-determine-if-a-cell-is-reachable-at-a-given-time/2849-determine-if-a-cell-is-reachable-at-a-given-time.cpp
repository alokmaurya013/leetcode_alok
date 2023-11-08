class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
       int width=abs(sx-fx);
  int height=abs(sy-fy);
  if(sx==fx&&sy==fy){
    if(t==1){
      return false;
    }
    return true;
  }  
  if(max(width,height)<=t){
    return true;
  }
  return false; 
    }
};
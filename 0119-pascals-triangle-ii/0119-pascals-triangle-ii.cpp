class Solution {
public:
    vector<int> getRow(int rowIndex) {
       vector<int>res(1,1);
  long long pre=1;
  for(int r=1;r<=rowIndex;r++){
    long long next=pre*(rowIndex-r+1)/r;
    res.push_back(next);
    pre=next;
  }
  return res; 
    }
};
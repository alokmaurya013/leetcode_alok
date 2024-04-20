class Solution {
public:
    vector<int>findprev(vector<int>& h,int n){
        stack<int>s;
        vector<int>prev(n,-1);
        s.push(-1);
        for(int i=0;i<n;i++){
            int c=h[i];
            while(s.top()!=-1&&h[s.top()]>=c){
                s.pop();
            }
             prev[i]=s.top();
            s.push(i);
        }
        return prev;
    }
    vector<int>findnext(vector<int>& h,int n){
        vector<int>next(n,n);
        stack<int>s;
        s.push(n);
        for(int i=n-1;i>=0;i--){
            int c=h[i];
            while(s.top()!=n&&h[s.top()]>=c){
                s.pop();
            }
             next[i]=s.top();
            s.push(i);
        }
        return next;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        int mx=0,area=0;
        vector<int>prev=findprev(heights,n);
        vector<int>next=findnext(heights,n);
        for(int i=0;i<n;i++){
            int l=next[i]-prev[i]-1;
            area=l*heights[i];
            mx=max(mx,area);
        }
        return mx;
    }
};
class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& p, vector<int>& h, string d) {
      vector<pair<int,pair<int,pair<int,char>>>>v;
        int n=p.size();
        for(int i=0;i<n;i++){
            v.push_back({p[i],{i,{h[i],d[i]}}});
        }
        sort(v.begin(),v.end());
        stack<pair<int,char>>st;
        vector<int>final(n,-1);
        for(int i=0;i<n;i++){
            int ind=v[i].second.first;
            int pos=v[i].first;
            int health=v[i].second.second.first;
            char ch=v[i].second.second.second;
            if(ch=='R'){
                st.push({ind,ch});
                final[ind]=health;
            }else{
                while(!st.empty()&&st.top().second=='R'){
                    int right=st.top().first;
                    int rightHealth=final[right];
                    if(rightHealth>health){
                        final[right]--;
                        health=-1;
                        break;
                    }else if(rightHealth<health){
                        final[right]=-1;
                        health--;
                        st.pop();
                    }else{
                        final[right]=-1;
                        health=-1;
                        st.pop();
                        break;
                    }
                }
                if(health>0){final[ind]=health;}
            }
        }
        vector<int>res;
        for(int i=0;i<n;i++){
            if(final[i]>0){
                res.push_back(final[i]);
            }
        }
        return res;
    }
};
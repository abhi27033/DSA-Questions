class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<pair<int,int>> stk;
        for(auto it:asteroids){
            if(it<0){
            while(stk.size()&&stk.top().second!=-1&&stk.top().first<-1*it)
            stk.pop();
            if(stk.size()&&stk.top().second!=-1){
                if(stk.top().first==-1*it)
                stk.pop();
            }
            else stk.push({it,-1});
            }
            else stk.push({it,1});
        }
        vector<int> ans;
        while(stk.size()){
            ans.push_back(stk.top().first);
            stk.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
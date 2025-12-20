class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        unordered_set<int> st;
        st.insert(0);
        sort(meetings.begin(),meetings.end(),[](vector<int>& a,vector<int>& b){return a[2]<b[2];});
        st.insert(firstPerson);
        vector<int> vis(n,-1);
        vector<vector<int>> adj(n);
        queue<int> q;
        for(int i=0;i<meetings.size();i++){
            int j=i;
            vector<int> pool;
            while(j<meetings.size()&&meetings[j][2]==meetings[i][2])
            {
                if(st.find(meetings[j][0])!=st.end()&&vis[meetings[j][0]]==-1){
                    q.push(meetings[j][0]);
                    vis[meetings[j][0]]=1;
                }
                if(st.find(meetings[j][1])!=st.end()&&vis[meetings[j][1]]==-1){
                    q.push(meetings[j][1]);
                    vis[meetings[j][1]]=1;
                }
                pool.push_back(meetings[j][0]);
                pool.push_back(meetings[j][1]);
                adj[meetings[j][0]].push_back(meetings[j][1]);
                adj[meetings[j][1]].push_back(meetings[j][0]);
                j++;
            }
            while(q.size()){
                int tp=q.front();
                q.pop();
                vis[tp]=-1;
                for(auto it:adj[tp]){
                    if(vis[it]==-1&&st.find(it)==st.end())
                    {
                        q.push(it);
                        vis[it]=1;
                        st.insert(it);
                    }
                }
            }
            for(auto it: pool)
            adj[it].clear();
            // cout<<q.size();
            i=j-1;
        }
        vector<int> ans;
        for(auto it:st)
        ans.push_back(it);
        return ans;
    }
};
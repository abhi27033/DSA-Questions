class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it:edges)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dis(n,-1);
        pq.push({0,0});
        while(pq.size())
        {
            auto it=pq.top();
            int node=it.second;
            pq.pop();
            if(dis[node]!=-1)continue;
            dis[node]=it.first;
            for(auto a:adj[node])
            {
                if(dis[a.first]==-1&&disappear[a.first]>it.first+a.second)
                {
                    pq.push({it.first+a.second,a.first});
                }
            }
        }
        return dis;
    }
};
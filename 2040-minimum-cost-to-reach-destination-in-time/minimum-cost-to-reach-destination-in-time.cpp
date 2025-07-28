class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n=passingFees.size();
        vector<unordered_map<int,int>> adj(n);
        for(auto it:edges){
            if(adj[it[0]].find(it[1])==adj[it[0]].end())
            adj[it[0]][it[1]]=it[2];
            else
            adj[it[0]][it[1]]=min(adj[it[0]][it[1]],it[2]);
            if(adj[it[1]].find(it[0])==adj[it[1]].end())
            adj[it[1]][it[0]]=it[2];
            else
            adj[it[1]][it[0]]=min(adj[it[1]][it[0]],it[2]);
        }
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        pq.push({passingFees[0],0,0});
        vector<vector<int>> dist(n,vector<int>(maxTime+1,INT_MAX));
        dist[0][0]=passingFees[0];
        while(pq.size()){
            int fees=pq.top()[0];
            int currentTime=pq.top()[1];
            int idx=pq.top()[2];
            pq.pop();
            // cout<<fees<<" "<<currentTime<<" "<<idx<<endl;
            if(idx==n-1)return fees;
            for(auto it:adj[idx]){
                if(currentTime+it.second<=maxTime&&dist[it.first][currentTime+it.second]>fees+passingFees[it.first])
                {
                    dist[it.first][currentTime+it.second]=fees+passingFees[it.first];
                    pq.push({fees+passingFees[it.first],currentTime+it.second,it.first});
                }
            }
        }
        return -1;
    }
};
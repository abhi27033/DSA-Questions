class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        unordered_map<int, unordered_map<int, int>> adj;
        vector<int> dis(n, INT_MAX);
        
        // Constructing the adjacency list and keeping track of the minimum weight for each edge
        for (int i = 0; i < edges.size(); ++i) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            
            if (adj[u].find(v) == adj[u].end() || adj[u][v] > w) {
                adj[u][v] = w;
                adj[v][u] = w; // Assuming undirected graph
            }
        }
        
        // Dijkstra's algorithm
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        dis[0] = 0;
        
        while (!pq.empty()) {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            
            if (d > dis[u]) continue;
            
            for (auto& [v, w] : adj[u]) {
                if (dis[v] > dis[u] + w && disappear[v] > dis[u] + w) {
                    dis[v] = dis[u] + w;
                    pq.push({dis[v], v});
                }
            }
        }
        
        // Handling nodes that cannot be reached within the given time
        for (int i = 0; i < n; ++i) {
            if (dis[i] >= disappear[i]) dis[i] = -1;
        }
        
        return dis;
    }
};

class Solution {
public:
bool checkCycle(vector<vector<int>>& adj, vector<int>& vis, int node) {
    if (vis[node] == 2) 
    {
        return true;  // Cycle detected
    }
    if (vis[node] == 0) {
        vis[node] = 2;
        for (auto it : adj[node]) {
            if (checkCycle(adj, vis, it)) {
                return true;
            }
        }
    }
    vis[node] = 1;  // Reset visited status
    return false;
}

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        int n=numCourses;
        if(prerequisites.size()==0)
        return 1;
        for(auto it:prerequisites)
        adj[it[1]].push_back(it[0]);
        bool x=false;
        vector<int> vis(n,0);
        for(int i=0;i<n;i++)
        {
            
            if(vis[i]==0)
            {
                bool z=checkCycle(adj,vis,i);
                x|=z;
            }
        }
        return !x;
    }
};
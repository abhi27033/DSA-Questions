class Solution {
public:
    int solve(int node,int par,int& ans,vector<vector<int>>& adj,vector<int>& val,int& k){
        int sum=0;
        for(auto it:adj[node]){
            if(it!=par){
                sum+=solve(it,node,ans,adj,val,k);
            }
        }
        sum+=val[node];
        if(sum%k==0)ans++;
        sum%=k;
        return sum;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        int ans=0;
        vector<vector<int>> adj(n);
        for(auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        solve(0,-1,ans,adj,values,k);
        return ans;
    }
};
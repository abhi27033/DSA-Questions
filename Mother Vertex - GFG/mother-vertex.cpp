//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution 
{
    public:
    //Function to find a Mother Vertex in the Graph.
    void solve(vector<int>adj[],int i,vector<int>&vis,stack<int>&s,int& c)
    {
        vis[i]=1;
        c++;
        for(auto it:adj[i])
        {
            if(vis[it]==-1)
            {
            solve(adj,it,vis,s,c);
            }
        }
        s.push(i);
    }
	int findMotherVertex(int V, vector<int>adj[])
	{
	    // Code here
	    int flg=-1;
	    vector<int> vis(V,-1);
	    stack<int> s;
	    for(int i=0;i<V;i++)
	    {
	        if(vis[i]==-1)
	        solve(adj,i,vis,s,flg);
	    }
	    int n=s.top();
	    stack<int> sk;
	    fill(vis.begin(),vis.end(),-1);
	    sk.push(n);
	    int c=1;
	   vis[n]=1;
	    while(sk.size())
	    {
	        int y=sk.top();
	        sk.pop();
	        for(auto it:adj[y])
	        {
    	        if(vis[it]==-1)
    	        {
    	            vis[it]=1;
    	        c++;
    	        sk.push(it);
    	        }
	        }
	    }
	    return c==V?n:-1;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
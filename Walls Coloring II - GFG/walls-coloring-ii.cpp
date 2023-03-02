//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minCost(vector<vector<int>> &costs) {
        // write your code here
        int n=costs.size();
	int m=costs[0].size();
	int dp[n][m];
	int x=0;

	for(auto it:costs[0])
	{
	    
        	dp[0][x++]=it;
	}
	x=0;
	for(int i=1;i<n;i++)
	{
	    	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	    for(int c=0;c<m;c++)
	    pq.push({dp[i-1][c],c});
	    for(int k=0;k<m;k++)
	    {
	       if(pq.top().second!=k)
	       {
    	    dp[i][k]=pq.top().first+costs[i][k];
	       }
	       else
	       {
	           if(pq.size()==1)
	           return -1;
	           pair<int,int> op=pq.top();
	           pq.pop();
	           dp[i][k]=pq.top().first+costs[i][k]; 
	           pq.push(op);
	       }
	    }
	   // for(auto it:dp[i])
	   // cout<<it<<" ";
	   // cout<<endl;
	}

	int ans=INT_MAX;
	for(int i=0;i<m;i++)
	ans=min(ans,dp[n-1][i]);
	return ans;
	
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> costs(n, vector<int>(k));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) cin >> costs[i][j];
        }
        Solution obj;
        cout << obj.minCost(costs) << endl;
    }
}
// } Driver Code Ends
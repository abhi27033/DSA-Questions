//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    bool dfs(vector<vector<int>>& matrix,vector<vector<int>>& vis,int i,int j, int N, int M)
    {
        if(i>=N||j>=M||i<0||j<0)
        return 0;
        if(matrix[i][j]==0||vis[i][j]==2)
        return 1;
        vis[i][j]=2;
        bool a=dfs(matrix,vis,i+1,j,N,M);
         bool b=dfs(matrix,vis,i,j+1,N,M);
          bool c=dfs(matrix,vis,i-1,j,N,M);
          bool d=dfs(matrix,vis,i,j-1,N,M);
          return a&&b&&c&&d;
    }
    int closedIslands(vector<vector<int>>& matrix, int N, int M) {
        // Code here
        vector<vector<int>> vis(N,vector<int>(M,-1));
        int ans=0;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                // cout<<vis[i][j]<<endl;
                if(vis[i][j]==-1&&matrix[i][j]==1&&dfs(matrix,vis,i,j,N,M)==1)
                {
                //  cout<<i<<" "<<j<<" "<<dfs(matrix,vis,i,j,N,M)<<endl;
                ans++;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends
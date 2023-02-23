//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int solve(vector<vector<int>>& grid, int x, int y, vector<vector<int>>& dp) {
        int n = grid.size();
        int m = grid[0].size();
        if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] != 1) {
            return 0;}
        if (x == n-1 && y == m-1) {
            return 1;}
        if (dp[x][y] != -1)
            return dp[x][y];
        long long paths = solve(grid, x+1, y, dp) + solve(grid, x, y+1, dp);
        paths %= 1000000007;
        dp[x][y] = paths;
        return dp[x][y];
    }
    int uniquePaths(int n, int m, vector<vector<int>>& grid) {
        if (n == 0 || m == 0 || grid[0][0] != 1) {
            return 0;
        }

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return solve(grid, 0, 0, dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,x;
        cin>>n>>m;
        
        vector<vector<int>> grid(n,vector<int>(m));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>grid[i][j];
            }
        }

        Solution ob;
        cout << ob.uniquePaths(n,m,grid) << endl;
    }
    return 0;
}
// } Driver Code Ends
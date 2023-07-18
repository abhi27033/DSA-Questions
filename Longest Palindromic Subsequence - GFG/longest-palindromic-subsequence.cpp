//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
//   int solve(string& a,int i,int j,vector<vector<int>>& dp)
//   {
//       if(i>j||j<0||i>=a.size())
//       return 0;
//       if(i==j)
//       return 1;
//       if(dp[i][j]!=-1)
//      return dp[i][j];
//       int ans=0;
//       if(a[i]==a[j])
//       ans=2+solve(a,i+1,j-1,dp);
//       else
//       ans=max(solve(a,i+1,j,dp),solve(a,i,j-1,dp));
//       return dp[i][j]=ans;
//   }
    int longestPalinSubseq(string A) {
        //code here
        int n=A.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        if(i==j)
        dp[i][j]=1;
        for(int i=n-1;i>=0;i--)
        {
            // dp[i][i]=1;
            for(int j=0;j<n;j++)
            {
                if(j>i)
                {
                if(A[i]==A[j])
                dp[i][j]=2+dp[i+1][j-1];
                else
                dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
                }
            }
        }
        return dp[0][n-1];
    }
};


//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends
//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  int solve(string& a,int i,int j,vector<vector<int>>& dp)
  {
      if(i>j||j<0||i>=a.size())
      return 0;
      if(i==j)
      return 1;
      if(dp[i][j]!=-1)
     return dp[i][j];
      int ans=0;
      if(a[i]==a[j])
      ans=2+solve(a,i+1,j-1,dp);
      else
      ans=max(solve(a,i+1,j,dp),solve(a,i,j-1,dp));
      return dp[i][j]=ans;
  }
    int longestPalinSubseq(string A) {
        //code here
        int n=A.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(A,0,n-1,dp);
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
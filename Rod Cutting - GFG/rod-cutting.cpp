//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
  int solve(int price[], int n,int q,vector<int>& dp)
  {
      int ans=0;
      if(dp[q]!=-1)
      return dp[q];
      for(int i=0;i<n;i++)
      {
          if(q-i-1>=0)
          {
            int z=price[i]+solve(price,n,q-i-1,dp);
            ans=max(ans,z);
          }
      }
      return dp[q]=ans;
  }
    int cutRod(int price[], int n) {
        //code here
        vector<int> dp(10001,-1);
        return solve(price,n,n,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends
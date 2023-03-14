//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<vector<int>>dp;
      int solve(int l, int r, const std::vector<int>& a) {
        if (l > r) return 0;
        if(dp[l][r]!=-1)
        return dp[l][r];
        int ma = INT_MIN;
        for (int i = l; i <= r; i++) {
            int left = (l-1 >= 0) ? a[l-1] : 1;
            int right = (r+1 < a.size()) ? a[r+1] : 1;
            ma = std::max(ma, (a[i] * left * right) + solve(l, i-1, a) + solve(i+1, r, a));
        }
        dp[l][r]=ma;
        return ma;
    }

    int maxCoins(int N, std::vector<int>& a) {
         dp.resize(N+2, vector<int>(N+2, -1));
        return solve(0, a.size()-1, a);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution S;
        cout<<S.maxCoins(n,a)<<endl;
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        // your code here
        int dp[n][m];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(S1[i]==S2[j])
                {
                    if(i>0&&j>0)
                dp[i][j]=dp[i-1][j-1]+1;
                else
                dp[i][j]=1;
                }
            }
        }
        int ma=INT_MIN;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
               // cout<<dp[i][j]<<" ";
                ma=max(ma,dp[i][j]);
            }
            //cout<<endl;
        }
        return ma;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends
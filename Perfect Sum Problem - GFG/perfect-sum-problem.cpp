//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{

	public:
	int m=1000000007;
	int solve(int ar[],int n,int s,int idx,int cs,vector<vector<int>>& dp)
	{
	    if(cs==s&&idx==n)
	    return 1;
	    if(cs>s||idx>=n)
	    return 0;
	    if(dp[idx][cs]!=-1)
	    return dp[idx][cs];
	    int a=solve(ar,n,s,idx+1,cs+ar[idx],dp)%m;
	    int b=solve(ar,n,s,idx+1,cs,dp)%m;
	    return dp[idx][cs]=(a+b)%m;
	}
	int perfectSum(int arr[], int n, int sum)
	{
	    vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
        return solve(arr,n,sum,0,0,dp);
	}
};


//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends
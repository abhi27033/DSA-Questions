//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    int m=1000000007;
    long long solve(int n,int s,vector<long long>& dp)
    {
        if(s>n)
        return 0;
        if(s==n)
        return 1;
        if(dp[s]!=-1)
        return dp[s];
        long long a=solve(n,s+1,dp);
        long long b=solve(n,s+2,dp);
        long long c=solve(n,s+3,dp);
        long long z=(a+b+c)%m;
        return dp[s]=z;
    }
    long long countWays(int n)
    {
        
        // your code here
        vector<long long> dp(n+1000,-1);
        return solve(n,0,dp);
        
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends
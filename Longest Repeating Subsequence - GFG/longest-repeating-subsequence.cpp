//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	int solve(int i,int j,string &a,string& b,vector<vector<int>>& dp)
	{
	    if(i>=a.size()||j>=b.size())
	    return 0;
	    if(dp[i][j]!=-1)
	    return dp[i][j];
	    int ans=0;
	    if(a[i]==b[j]&&i!=j)
	    ans=1+solve(i+1,j+1,a,b,dp);
	    else
	    ans=max(solve(i+1,j,a,b,dp),solve(i,j+1,a,b,dp));
	    return dp[i][j]=ans;
	}
		int LongestRepeatingSubsequence(string str){
		    // Code here
		    int i=0,j=0,n=str.size();
		   vector<vector<int>> dp(n,vector<int>(n,-1));
		    return solve(0,0,str,str,dp);
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
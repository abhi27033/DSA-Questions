//{ Driver Code Starts
//Initial Template for CPP

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    long long maxTripletProduct(long long arr[], int n)
    {
    	// Complete the function
    	sort(arr,arr+n);
    	long long m=arr[0];
    	m*=arr[1];
    	long long w=arr[n-2];
    	w*=arr[n-3];
    	long long ans=max(m,w);
    	ans*=arr[n-1];
    	if(ans<0)
    	{
    	    ans=arr[n-1];
    	    ans*=arr[n-2];
    	    ans*=arr[n-3];
    	}
    	return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,i;
	    cin>>n; long long arr[n];
	    for(i=0;i<n;i++)
	    cin>>arr[i];
	    Solution ob;
	    cout <<ob.maxTripletProduct(arr, n);
	    cout<<"\n";
	}
    return 0;
}
// } Driver Code Ends
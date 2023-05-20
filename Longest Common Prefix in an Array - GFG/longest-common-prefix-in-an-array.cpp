//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
    string longestCommonPrefix (string arr[], int N)
    {
        // your code here
        int k=0;
        string ans;
        while(k<arr[0].size())
        {
        for(int i=1;i<N;i++)
        {
            if(arr[i].size()==k||arr[i][k]!=arr[0][k])
            return ans.size()==0?"-1":ans;
        }
        ans+=arr[0][k];
        k++;
        
        }
        return ans.size()==0?"-1":ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends
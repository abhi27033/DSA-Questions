//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
   public:
    const long M = 1000000007;
    vector<vector<long long>> mul(vector<vector<long long>>&a,vector<vector<long long>>&b)
    {
        vector<vector<long long>> ans(2,vector<long long>(2,0));
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<2;j++)
            {
                for(int k=0;k<2;k++)
                {
                    ans[i][j]=(ans[i][j]+(a[i][k]*b[k][j])%M)%M;
                }
            }
        }
        return ans;
    }
    vector<vector<long long>> solve(vector<vector<long long>>&m,long long pow)
    {
        if(pow==1)
        return m;
        vector<vector<long long>> t=solve(m,pow/2);
        vector<vector<long long>> ans=mul(t,t);
        if(pow&1)
        {
            ans=mul(ans,m);
        }
        return ans;
    }
    int countStrings(long long int N)
    {
        vector<vector<long long>> m(2,vector<long long>(2,0));
        if(N==2)
        return 3;
        if(N==1)
        return 2;
        m[0][0]=0;
        m[0][1]=1;
        m[1][0]=1;
        m[1][1]=1;
        vector<vector<long long>> ans=solve(m,N-2);
        return (2*ans[0][1]+3*ans[1][1])%M;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int N;
        cin >> N;
        Solution obj;
        cout << obj.countStrings(N) << endl;
    }
}
// } Driver Code Ends
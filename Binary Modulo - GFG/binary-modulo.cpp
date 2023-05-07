//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        int modulo(string s,int m)
        {
            //code here
            int pre[s.size()+1];
            pre[0]=1;
            for(int i=1;i<=s.size();i++)
            pre[i]=(pre[i-1]<<1)%m;
            int n=0;
            int ans=0;
            for(int i=s.size()-1;i>=0;i--)
            {
                int t=s[i]-'0';
                ans=(ans+(t*pre[n++])%m)%m;
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
        string s;
        int m;
        cin>>s>>m;
        Solution a;
        cout<<a.modulo(s,m)<<endl;
    }
    return 0;
}
// } Driver Code Ends
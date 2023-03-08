//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    bool isPossible(int n,int k,int w,vector<int> a,long long int num)
    {
        for(int i=0;i<n;i++)
        {
            if(a[i]<num)
            {
                int x=num-a[i];
                if(x>k)
                return false;
                k-=x;
                a[i]=num;
                for(int j=i+1;(j<i+w)&&(j<n);j++)
                a[j]+=x;
            }
        }
        return true;
    }
    public:
        long long int maximizeMinHeight(int n,int k,int w,vector <int> &a)
        {
            // code here
            long long int l=1,r=9999999999;
            while(l<=r)
            {
                int m=(l+r)/2;
                if(isPossible(n,k,w, a,m))
                l=m+1;
                else
                r=m-1;
            }
            return l-1;
            
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k,w;
        cin>>n>>k>>w;
        vector <int> a(n);
        for(auto &j:a)
            cin>>j;
        Solution s;
        cout<<s.maximizeMinHeight(n,k,w,a)<<endl;
    }
    return 0;
}
// } Driver Code Ends
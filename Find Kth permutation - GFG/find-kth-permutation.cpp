//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
int bin(vector<int>& ans,int ele,int l,int r)
{
   while(l<=r)
   {
       int mid=(l+r)/2;
       if(ele<=ans[mid])
       l=mid+1;
       else
       r=mid-1;
   }
   return l-1;
}
void reverse(int l,int r,vector<int>&a)
{
    while(l<=r)
    {
        int t=a[l];
        a[l]=a[r];
        a[r]=t;
        l++;
        r--;
    }
}
void next(vector<int>&c)
{
    int n=c.size();
    int i=n-2;
    while(i>=0&&c[i]>=c[i+1])
    i--;
    if(i<0)
    {
        sort(c.begin(),c.end());
        
    }
    else
    {
        int idx=(bin(c,c[i],i+1,n-1));
        // cout<<i<<" "<<idx<<endl;
        int t=c[idx];
        c[idx]=c[i];
        c[i]=t;
        reverse(i+1,n-1,c);
        
    }
}
    string kthPermutation(int n, int k)
    {
        // code here
        vector<int> q;
        for(int i=1;i<=n;i++)
        q.push_back(i);
        // next(q);
        k--;
        while(k--)
        {
        //     for(auto it:q)
        // cout<<it<<" ";
        // cout<<endl;
        next(q);
        }
        
        string ans="";
        for(int i=0;i<n;i++)
        {
            char a=(((q[i])+'0'));
            // cout<<a<<endl;
           ans+=a;
            
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        Solution ob;
        string ans = ob.kthPermutation(n, k);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
class Solution {
public:
    int findK(int a[MAX][MAX], int n, int m, int k) {
        int t = 0;
        while (1) {
            // Check if the array is square and we have reached the center element
            if (n == m && (n / 2) + 1 == t)
                return a[t][t];
            
            int j = t;
            
            // Traverse the top row from left to right
            while (j < m - t) {
                if (--k == 0)
                    return a[t][j];
                j++;
            }
            
            int i = t + 1;
            
            // Traverse the right column from top to bottom
            while (i < n - t) {
                if (--k == 0)
                    return a[i][j - 1];
                i++;
            }
            
            int kk = m - 1 - t;
            
            // Traverse the bottom row from right to left
            while (kk > t) {
                if (--k == 0)
                    return a[i - 1][kk - 1];
                kk--;
            }
            
            int ll = n - 1 - t;
            
            // Traverse the left column from bottom to top
            while (ll > t + 1) {
                if (--k == 0)
                    return a[ll - 1][kk];
                ll--;
            }
            
            t++;
        }
    }
};






//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends
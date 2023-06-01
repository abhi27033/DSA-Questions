//{ Driver Code Starts
// Driver code

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
  public:
    int findOnce(int arr[], int n)
    {
        //code here.
        int l=0,r=n-1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(arr[mid]==arr[mid-1])
            {
                if((mid+1)%2==0)
                l=mid+1;
                else
                r=mid-1;
            }
            else if(arr[mid]==arr[mid+1])
            {
                if((mid+1)%2==1)
                l=mid+1;
                else
                r=mid-1;
            }
            else
            {
                return arr[mid];
            }
        }
        return arr[l];
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int A[n];
        for(int i = 0;i < n;i++)
        {
            cin>>A[i];
        }
        
        Solution ob;
        
        int res = ob.findOnce(A,n);
        cout << res << endl;
    }
    
    return 0;
}
// } Driver Code Ends
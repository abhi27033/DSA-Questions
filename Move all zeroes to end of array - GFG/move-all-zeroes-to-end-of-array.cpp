//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	void pushZerosToEnd(int arr[], int n) {
	    // code here
	    int i=0,c=0;
	    for(int i=0;i<n;i++)
	    if(arr[i]==0)
	    c++;
	    for(int j=0;j<=n;j++)
	    {
	        if(arr[j]!=0)
	        
	        {
	            swap(arr[j],arr[i++]);
	        }
	       //for(int ii=0;ii<n;ii++)
	       //cout<<arr[ii]<<" ";
	       //cout<<endl;
	    }
	    for(int j=n-1;j>=0&&c>0;j--)
	    arr[j]=0,c--;
	}
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.pushZerosToEnd(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
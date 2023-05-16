//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends

class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        long long s=0,q=-1;
        for(int i=0;i<n;i++)
        {
            int idx=abs(arr[i])-1;
            if(arr[idx]<0)
            {
                q=abs(arr[i]);
            }
            else
            {
                arr[idx]*=-1;
            }
            s+=abs(arr[i]);
        }
        
        s-=q;
        long long z=n;
        z*=(n+1);
        z/=2;
        z-=s;
        return {(int)q,(int)z};
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends
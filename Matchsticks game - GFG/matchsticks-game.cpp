//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int matchGame(long long N) {
        // code here
        if(N<=4)
        return N;
        if(N%5==0)
        return -1;
        int s=N/5;
        N-=s;
        int ans=N%4;
        
        return ans==0?4:ans;
        // 6 1
        // 7 2
        // 8 3
        // 9 4
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.matchGame(N) << endl;
    }
    return 0;
}
// } Driver Code Ends
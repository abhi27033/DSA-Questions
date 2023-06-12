//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int cutRod(int price[], int n) {
        vector<int> dp(n + 1, 0); // dp[i] stores the maximum profit for a rod of length i

        for (int i = 1; i <= n; i++) {
            int maxProfit = 0;

            for (int j = 0; j < i; j++) {
                maxProfit = max(maxProfit, price[j] + dp[i - j - 1]);
            }

            dp[i] = maxProfit;
        }

        return dp[n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends
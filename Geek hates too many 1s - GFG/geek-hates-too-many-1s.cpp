//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {

  public:
    int noConseBits(int n) {
        // code here
        int nbits=(int)log2(n)+1;
        int cnt=0;
        int i;
        for(i=0;i<nbits;i++)
        {
            if((n&(1<<i)))
            cnt++;
            else
            {
                if(cnt>=3)
                {
                    int j=i-3;
                    while(j>=i-cnt)
                    {
                        n&=~(1<<j);
                        j-=3;
                    }
                }
            cnt=0;
            }
            
        }
        
        
        if(cnt>=3)
                {
                    int j=i-3;
                    while(j>=i-cnt)
                    {
                        n&=~(1<<j);
                        j-=3;
                    }
                }
        return n;
    }
};


//{ Driver Code Starts.

int main() {

    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {

        int n;
        cin >> n;
        int ans = sol.noConseBits(n);
        cout << ans << '\n';
    }

    return 0;
}

// } Driver Code Ends
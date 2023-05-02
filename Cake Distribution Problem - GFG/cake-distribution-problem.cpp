//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    int maxSweetness(vector<int>& sweetness, int N, int K) {
    // Write your code here.
    int s=0;
    for(int i=0;i<N;i++)
    s+=sweetness[i];
    
    int l=1,h=s,ans;
    while(l<=h)
    {
        int m=l+(h-l)/2;
        int p=0,ss=0;
        for(int i=0;i<N;i++)
        {
            ss+=sweetness[i];
            if(ss>=m)
            {
                p++;
                ss=0;
            }
        }
        if(p<K+1)
        h=m-1;
        else
        {
            ans=m;
            l=m+1;
        }
    }
    return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> sweetness(n);
        for (int i = 0; i < n; i++) {
            cin >> sweetness[i];
        }
          Solution ob;
          int res=ob.maxSweetness(sweetness, n, k);
        cout << res << endl;
    }
}
// } Driver Code Ends
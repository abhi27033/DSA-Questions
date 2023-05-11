//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int minimumSum(string s) {
        int n = s.length();
        int l = 0,r = n-1;
        while(l<=r)
        {
            if(s[l]!='?'&&s[r]!='?')
            {
                if(s[l]!=s[r])
                return -1;
            }
            else if(s[l]=='?'&&s[r]!='?')
            {
                s[l]=s[r];
            }
            else if(s[l]!='?'&&s[r]=='?')
            {
                s[r]=s[l];
            }
            l++;
            r--;
        }
        string x;
        for(auto it:s)
        if(it!='?')
        x+=it;
        //cout<<x<<endl;
        int ans=0;
        if(x=="")
        return 0;
      for(int i=0;i<x.size()-1;i++)
      ans+=abs((int)x[i]-(int)x[i+1]);
       return ans;
    }
};
 

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        int ans = ob.minimumSum(s);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
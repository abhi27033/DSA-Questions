//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxIntersections(vector<vector<int>> lines, int N) {
        // Code here
        vector<pair<int,int>> v;
        for(auto it:lines)
        {
            v.push_back({it[0],1});
            v.push_back({it[1],2});
        }
        sort(v.begin(),v.end());
        int ans=INT_MIN,p=0;
        for(auto it:v)
        {
            if(it.second==1)
            p++;
            else
            p--;
            ans=max(ans,p);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> mat(N, vector<int>(2));
        for (int j = 0; j < 2; j++) {
            for (int i = 0; i < N; i++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        cout << obj.maxIntersections(mat, N) << endl;
    }
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int leastInterval(int N, int K, vector<char> &tasks) {
        // code here
        unordered_map<char,int> mp;
        int ma=INT_MIN,g=0;
        for(auto it:tasks)
        mp[it]++,ma=max(ma,mp[it]);
        for(auto it:mp)
        if(it.second==ma)
        g++;
        g--;
        int y=((ma-1)*K+ma+g);
        return max(N,y);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<char> tasks(N);
        for (int i = 0; i < N; i++) cin >> tasks[i];

        Solution obj;
        cout << obj.leastInterval(N, K, tasks) << endl;
    }
    return 0;
}
// } Driver Code Ends
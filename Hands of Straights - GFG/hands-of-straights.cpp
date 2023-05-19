//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isStraightHand(int N, int groupSize, vector<int> &hand) {
        // code here
        unordered_map<int,int> mp;
        sort(hand.begin(),hand.end());
        for(auto it:hand)
        mp[it]++;
        for(auto it:hand)
        {
            if(mp[it]==0)
            continue;
            mp[it]--;
            it++;
            for(int i=1;i<groupSize;i++)
            {
                
                if(mp[it]==0)
                return false;
                mp[it]--;
                it++;
            }
        }
        for(auto it:mp)
        if(it.second>0)
        return false;
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, groupSize;
        cin >> N >> groupSize;

        vector<int> hand(N);
        for (int i = 0; i < N; i++) cin >> hand[i];

        Solution obj;
        int ans = obj.isStraightHand(N, groupSize, hand);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends
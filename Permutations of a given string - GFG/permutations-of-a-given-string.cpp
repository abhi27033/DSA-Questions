//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void nextPermutation(string& s) {
        int n = s.length();
        int i = n - 2;
        while (i >= 0 && s[i] >= s[i + 1]) {
            i--;
        }
        if (i < 0) {
            sort(s.begin(), s.end());
        } else {
            int j = n - 1;
            while (j > i && s[j] <= s[i]) {
                j--;
            }
            swap(s[i], s[j]);
            reverse(s.begin() + i + 1, s.end());
        }
    }
    
    vector<string> find_permutation(string S) {
        vector<string> permutations;
        sort(S.begin(), S.end());  // Sort the string to ensure lexicographically sorted output
        permutations.push_back(S);
        
        while (true) {
            nextPermutation(S);
            if (S == permutations[0]) {
                break;
            }
            permutations.push_back(S);
        }
        
        return permutations;
    }
};




//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends
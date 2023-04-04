//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

int minSteps(string str) {
    // Write your code here.
    string x;
    int i=0;
    while(i<str.size())
    {
        int j=i;
        x.push_back(str[i]);
        while(i<str.size()&&str[i]==str[j])
        i++;
    }
    int n=x.size()+1;
    int ans=ceil(n/2.0);
    //cout<<x<<endl;
    return ans;
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        cout << minSteps(str) << endl;
    }
}

// } Driver Code Ends
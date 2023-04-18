//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int solve(string S,int &i,int &j)
    {
        int f=0,ans=INT_MIN;
        while(i<S.size()&&S[i]=='0')
        {
            i++,f++;
        }
        //cout<<f<<endl;
        ans=max(ans,f);
        f=0;
        while(j>=0&&S[j]=='0')
        j--,f++;
        //cout<<f<<endl;
        ans=max(ans,f);
        return ans;
    }
    bool wifiRange(int N, string S, int X){
        // code here
        int ans=INT_MIN;
        int i=0,j=N-1;
        if(solve(S,i,j)>X)
        return 0;
        // cout<<i<<" "<<j<<endl;
        // cout<<ans<<endl;
        while(i<=j)
        {
            if(S[i]=='0')
            {
                int t=0;
                while(i<=j&&S[i]=='0')
                t++,i++;
                ans=max(ans,t);
            }
            else
            i++;
        }
        if(ans<=2*X)
        return 1;
        return 0;
        
    }
};

//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, X;
        string S;
        cin >> N >> X >> S;
        Solution obj;
        cout << obj.wifiRange(N, S, X) << "\n";
    }
}

// } Driver Code Ends
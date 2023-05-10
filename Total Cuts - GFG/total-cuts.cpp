//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int totalCuts(int N,int K,vector<int> &A){
        vector<int> a,b;
        int m=A[0];
        for(int i=0;i<N;i++)
        {
            m=max(A[i],m);
            a.push_back(m);
        }
        a.pop_back();
      m=A[N-1];
        for(int j=N-1;j>=0;j--)
        {
            m=min(A[j],m);
            b.push_back(m);
        }
        b.pop_back();
        reverse(b.begin(),b.end());
        int ans=0;
        for(int i=0;i<N-1;i++)
        {
            if(a[i]+b[i]>=K)
            ans++;
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N,K;
        cin>>N>>K;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution ob;
        cout<<ob.totalCuts(N,K,A)<<endl;
    }
    return 0;
}
// } Driver Code Ends
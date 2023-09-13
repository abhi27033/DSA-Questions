//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int N, int S){
        // code here
        int q=S/9;
        int r=S%9;
        if(S==0)
        {
            if(N==1)
            return "0";
            else 
            return "-1";
        }
        // cout<<r<<endl;
        int x=0;
        if(r!=0)
        x++;
        if(x+q>N)
        return "-1";
        string ans;
        for(int i=0;i<q;i++)
        ans+='9';
        if(r!=0)
        ans+=(r+'0');
        int z=N-(x+q);
        while(z--)
        ans+='0';
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
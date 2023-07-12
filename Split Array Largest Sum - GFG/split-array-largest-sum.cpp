//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  bool solve(int arr[],int N,int sum,int k)
  {
      int i=0;
      int t=sum;
      while(i<N)
      {
          t-=arr[i];
          if(t<0)
          {
          t=sum;
          k--;
          if(k==0)
          return false;
          continue;
          }
          i++;
      }
      return true;
  }
    int splitArray(int arr[] ,int N, int K) {
        // code here
        int s=0;
        for(int i=0;i<N;i++)
        s+=arr[i];
        int l=1,r=s;
        while(l<=r)
        {
            int m=l+(r-l)/2;
            // cout<<m<<endl;
            if(solve(arr,N,m,K))
            r=m-1;
            else
            l=m+1;
        }
        return l;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends
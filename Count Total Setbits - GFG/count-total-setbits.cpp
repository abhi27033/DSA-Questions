//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    long long countBits(long long N) {
        // code here
        N++;
        long long a=N;
        long long x=0;
        long long ans=0;
        while(N)
        {
            x++;
            N=N>>1;
            
        }
        // cout<<x<<endl;
        for(long long i=0;i<x;i++)
        {
            long long z = pow(2,i+1);
            long long groups_done = a/z;
            long long temp = a%(z);
            // temp=a-temp;
        //   cout<<temp<<endl;
            if(temp>z/2)
            {
            temp-=(z/2);
            // temp++;
            //   cout<<temp<<endl;
            ans+=temp;
            }
            long long bits_done_over_groups_done = groups_done*(z/2);
            ans+=bits_done_over_groups_done;
            
            //  cout<<z<<" "<<groups_done<<" "<<bits_done_over_groups_done<<endl;
            //now we want to add the remaining bits
            // long long half_range=pow(2,z/2)-1;
            
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        long long N;
        scanf("%lld",&N);
        
        Solution obj;
        long long res = obj.countBits(N);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    long long countSetBits(long long N) {
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
        for(long long i=0;i<x;i++)
        {
            long long z = pow(2,i+1);
            long long groups_done = a/z;
            long long temp = a%(z);
            if(temp>z/2)
            {
            temp-=(z/2);
            ans+=temp;
            }
            long long bits_done_over_groups_done = groups_done*(z/2);
            ans+=bits_done_over_groups_done;
            
        }
        return ans;
    }
};

//{ Driver Code Starts.

// Driver code
int main()
{
	 int t;
	 cin>>t;// input testcases
	 while(t--) //while testcases exist
	 {
	       int n;
	       cin>>n; //input n
	       Solution ob;
	       cout << ob.countSetBits(n) << endl;// print the answer
	  }
	  return 0;
}

// } Driver Code Ends
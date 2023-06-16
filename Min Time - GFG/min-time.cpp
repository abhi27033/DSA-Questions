//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  unordered_map<int,int>m1,m2;
  long long help(long long i,vector<long long>&t,long long pos,vector<vector<long long>>&dp,int pp)
  {
      if(i==t.size())
      {
          return abs(pos-0);
      }
      if(dp[i][pp]!=-1)
      return dp[i][pp];
      long long mi=m1[t[i]],ma=m2[t[i]];
      long long l=abs(mi-pos)+abs(mi-ma)+help(i+1,t,ma,dp,0);
      long long r=abs(ma-pos)+abs(mi-ma)+help(i+1,t,mi,dp,1);
      return dp[i][pp]=min(l,r);
  }
    long long minTime(int n, vector<int> &locations, vector<int> &types) {
        // code here
        int m=INT_MIN;
        for(auto it:types)
        m=max(m,it);
        vector<int> r(m+1,0);
        for(auto it:types)
        r[it]=1;
        vector<long long> t;
        for(int i=0;i<=m;i++)
        if(r[i]==1)t.push_back(i);
        // for(auto it:t)
        // cout<<it<<endl;
        for(int i=0;i<types.size();i++)
        {
            if(m1.find(types[i])==m1.end())
            {
                m1[types[i]]=locations[i];
                m2[types[i]]=locations[i];
            }
            else
            {
                m1[types[i]]=min(m1[types[i]],locations[i]);
                m2[types[i]]=max(m2[types[i]],locations[i]);
            }
        }
        vector<vector<long long>> dp(t.size()+1,vector<long long>(2,-1));
        return help(0,t,0,dp,0);
        
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        
        
        vector<int> locations(n);
        for(int i=0;i<n;i++){
            cin>>locations[i];
        }
        
        
        vector<int> types(n);
        for(int i=0;i<n;i++){
            cin>>types[i];
        }
        
        Solution obj;
        long long res = obj.minTime(n, locations, types);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
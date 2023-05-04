//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxCoins(int n,vector<vector<int>> &ranges){
        // Code here
        sort(ranges.begin(),ranges.end());
        vector<pair<int,int>> a;
        for(auto it:ranges)
        {
            a.push_back({it[0],it[2]});
        }
        int ma=INT_MIN;
        for(int i=n-1;i>=0;i--)
        {
            ma=max(ma,ranges[i][2]);
            a[i].second=ma;
        }
        // for(auto it:a)
        // {
        // cout<<it.first<<" "<<it.second<<endl;
        // }
        int ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            int low=i+1,high=n-1,end=ranges[i][1];
            while(low<=high)
            {
                int mid=(low+high)/2;
                if(a[mid].first>=end)
                high=mid-1;
                else
                low=mid+1;
            }
            if(low==n)
            ans=max(ans,ranges[i][2]);
            else
            ans=max(ans,ranges[i][2]+a[low].second);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> a(n,vector<int>(3));
        for(int i=0;i<n;i++){
            cin>>a[i][0]>>a[i][1]>>a[i][2];
        }
        Solution ob;
        cout<<ob.maxCoins(n,a)<<endl;
    }
    return 0;
}
// } Driver Code Ends
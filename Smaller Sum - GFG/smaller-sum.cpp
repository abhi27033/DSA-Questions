//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
int search(int ele,vector<int>&b,int l,int h)
{
    while(l<=h)
    {
        int m=(l+h)/2;
        if(b[m]<ele)
        l=m+1;
        else
        h=m-1;
    }
    return l;
}
    vector<long long> smallerSum(int n,vector<int> &arr){
       vector<int> b=arr;
       sort(b.begin(),b.end());
       vector<long long> pre;
       pre.push_back(0);
       for(int i=0;i<n;i++)
       pre.push_back(pre[i]+b[i]);
    //   for(int i=0;i<n;i++)
    //   cout<<b[i]<<" ";
    //   cout<<endl;
    //   for(int i=0;i<=n;i++)
    //   cout<<pre[i]<<" ";
    //   cout<<endl;
       vector<long long> ans;
       for(int i=0;i<n;i++)
       {
           int idx=search(arr[i],b,0,n-1);
        //  cout<<idx<<" "<<arr[i]<<endl;
           ans.push_back(pre[idx]);
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
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob; 
        vector<long long> ans=ob.smallerSum(n,arr);
        for(int i=0;i<n;i++){
            if(i!=n-1){
                cout<<ans[i]<<" ";
            }
            else{
                cout<<ans[i]<<endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends
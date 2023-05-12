//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int arrayOperations(int n, vector<int> &arr) {
        // code here
        int ans=0;
        int flg=1;
        int z=0,t=0;
        for(auto it:arr)
        if(it==0)
        t++;
        if(t==0)
        return -1;
        arr.push_back(0);
        for(int i=0;i<=n;i++)
        {
            
            if(arr[i]==0)
            {
            flg=1;
            if(z>0)
            {
            ans++;z=0;
            //cout<<i<<endl;
            }
            }
            else if(flg==1)
            {
                z++;
            }
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
        
        Solution obj;
        int res = obj.arrayOperations(n, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
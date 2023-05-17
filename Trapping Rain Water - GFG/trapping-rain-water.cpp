//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // code here
        vector<int>p1(n),p2(n);
        int ma=INT_MIN;
        for(int i=0;i<n;i++)
        {
            ma=max(ma,arr[i]);
            p1[i]=ma;
        }
        ma=INT_MIN;
        for(int i=n-1;i>=0;i--)
        {
            ma=max(ma,arr[i]);
            p2[i]=ma;
        }
        // for(int i=0;i<n;i++)
        // cout<<p1[i]<<" ";
        // cout<<endl;
        // for(int i=0;i<n;i++)
        // cout<<p2[i]<<" ";
        // cout<<endl;
        // reverse(p2.begin(),p2.end());
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            int m=min(p1[i],p2[i]);
            // cout<<m<<" "<<arr[i]<<endl;
            // cout<<(m-arr[i])<<endl;
            ans+=(m-arr[i]);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends
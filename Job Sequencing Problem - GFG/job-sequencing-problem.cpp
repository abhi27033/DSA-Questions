//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        vector<pair<int,int>> v;
        int dm=INT_MIN;
        for(int i=0;i<n;i++)
        {
        v.push_back({arr[i].profit,arr[i].dead});
        dm=max(dm,arr[i].dead);
        
        }
        //cout<<dm<<endl;
        vector<int> d(dm+1,1);
        // for(int i=0;i<=dm;i++)
        // {
        // d[i]=i;
        // }
        
       sort(v.begin(),v.end(),greater<pair<int,int>>());
       int q=0,ans=0;
       for(auto it:v)
       {
           int p=it.first;
           int de=it.second;
           int i=de;
           int flg=0;
           while(i>0)
           {
               if(d[i]>0)
               {
                   flg=1;
                   d[i]--;
                   break;
               }
               i--;
           }
           if(flg==1)
           {
               q++;
               ans+=p;
           }
           
       }
       vector<int>z={q,ans};
       return z;
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends
//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    vector<int> nearestSmallerTower(vector<int> arr)
    {
      vector<int> a1;
      vector<int> a2;
      vector<int> ans;
      stack<int> s1,s2;
      for(int i=0;i<arr.size();i++)
      {
          int a=arr[i];
          while(!s1.empty()&&arr[s1.top()]>=a)
          s1.pop();
          if(s1.empty())
              a1.push_back(-1);
          else
              a1.push_back(s1.top());
         s1.push(i);
      }
      for(int i=arr.size()-1;i>=0;i--)
      {
          int a=arr[i];
          while(!s2.empty()&&arr[s2.top()]>=a)
          s2.pop();
          if(s2.empty())
              a2.push_back(-1);
          else
              a2.push_back(s2.top());
         s2.push(i);
      }
      reverse(a2.begin(),a2.end());
      for(int i=0;i<arr.size();i++)
      {
          if(a1[i]==-1&&a2[i]==-1)
          {
              ans.push_back(-1);
          }
         
          else if(a2[i]==-1)
          {
              ans.push_back(a1[i]);
          }
          else  if(a1[i]==-1)
          {
              ans.push_back(a2[i]);
          }
          else
          {
             int di1=abs(i-a1[i]);
             int di2=abs(i-a2[i]);
             if(di1==di2)
             {
                 if(arr[a1[i]]==arr[a2[i]])
                 ans.push_back(a1[i]);
                 else
             ans.push_back(arr[a1[i]]<arr[a2[i]]?a1[i]:a2[i]);
             }
             else if(di1<di2)
             {
                 ans.push_back(a1[i]);
             }
             else
             {
                 ans.push_back(a2[i]);
             }
          }
      }
    // for(auto it:a1)
    // cout<<it<<" ";
    // cout<<endl;
       return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution ob;
        vector<int> ans = ob.nearestSmallerTower(v);
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
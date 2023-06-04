//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseEqn (string s)
        {
            //code here.
            stack<string> stk;
            string t;
            for(auto it:s)
            {
               if(it=='+'||it=='-'||it=='*'||it=='/')
               {
                   stk.push(t);
                   t="";
                   t+=it;
                   stk.push(t);
                   t="";
               }
               else
               {
                   t+=it;
               }
            }
            if(t!="")
            stk.push(t);
            string ans;
            while(!stk.empty())
            {
                ans+=stk.top();
                stk.pop();
            }
            return ans;
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends
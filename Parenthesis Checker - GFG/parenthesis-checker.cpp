//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        stack<char> stk;
        for(auto it:x)
        {
          if(it=='{'||it=='['||it=='(')
          stk.push(it);
          else
          {
              if(!stk.empty())
              {
              char c=stk.top();
              if(it=='}'&&c!='{')
              return false;
              if(it==')'&&c!='(')
              return false;
              if(it==']'&&c!='[')
              return false;
              stk.pop();
              }
              else
              return false;
          }
        }
        if(stk.empty())
        return true;
        return false;
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int checkCompressed(string S, string T) {
        int i=0,x=0,r=0;
        // for(int c=0;c<T.size();c++)
        // {
        //     if(T[i]>='0'&&T[i]<='9')
        //     {
        //      if(flg==0)
        //      flg=1;
        //      else
        //      return 0;
        //      continue;
        //     }
        //     flg=0;
            
        // }
        while(i<T.size())
        {
            //cout<<T[i]<<S[x]<<"\n";
            if(T[i]>='0'&&T[i]<='9')
            {
            r=((r*10)+((T[i]-'0')));
           // cout<<r<<endl;
            i++;
            continue;
            }
            else
            {
                //cout<<r<<endl;
                x+=r;
                r=0;
                //cout<<S[x]<<endl;
                if(x<S.size()&&S[x]!=T[i])
                return 0;
                else
                x++;
            }
            i++;
        }
        if(x+r==S.size())
        return 1;
        return 0;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S,T;
        
        cin>>S>>T;

        Solution ob;
        cout << ob.checkCompressed(S,T) << endl;
    }
    return 0;
}
// } Driver Code Ends
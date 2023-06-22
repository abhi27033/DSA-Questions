//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool lemonadeChange(int N, vector<int> &bills) {
        // code here
        int f=0,t=0,r=0;
        for(int i=0;i<N;i++)
        {
            int g=bills[i];
            // cout<<f<<" "<<t<<" "<<r<<endl;
            g-=5;
            if(g>0)
            {
                if(g==5)
                {
                    if(f==0)
                    return false;
                    f--;
                }
                else
                {
                    if(t==0)
                    {
                        if(f<3)
                        return false;
                        f-=3;
                    }
                    else
                    {
                        if(f==0)
                        return false;
                        t--;
                        f--;
                    }
                }
               
            }
             g=bills[i];
                if(g==5)
                f++;
            else if(g==10)
                t++;
            else
                r++;
        }
        return true;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> bills(N);
        for (int i = 0; i < N; i++) cin >> bills[i];

        Solution obj;
        int ans = obj.lemonadeChange(N, bills);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends
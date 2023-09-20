//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
  public:
        vector <int> rotate (int n, int d)
        {
            //code here.
            d%=16;
            string s;
            while(n)
            {
                s+=((n&1)+'0');
                n>>=1;
            }
            int nn=16-s.size();
            while(nn--)
            s+='0';
            reverse(s.begin(),s.end());
            string s1(16,'0');
            string s2(16,'0');
            for(int i=0;i<16;i++)
            s1[(i+d)%16]=s[i];
            for(int i=0;i<16;i++)
            {
                int y=(i-d);
                if(y>=0)
                s2[y]=s[i];
                else
                s2[16+y]=s[i];
            }
            // cout<<s<<endl;
            // cout<<s1<<endl;
            // cout<<s2<<endl;
            int a=0,b=0;
            int c=15;
            for(auto it:s1)
            {
                if(it=='1')
                a+=(pow(2,c));
                c--;
            }
            c=15;
            for(auto it:s2)
            {
                if(it=='1')
                b+=(pow(2,c));
                c--;
            }
            vector<int> ans;
            ans.push_back(b);
            ans.push_back(a);
            return ans;
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        
        int n, d; cin >> n >> d;
        Solution ob;
        vector <int> res = ob.rotate (n, d);
        cout << res[0] << endl << res[1] << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends
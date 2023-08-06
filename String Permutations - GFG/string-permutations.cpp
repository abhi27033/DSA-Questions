//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    void solve(vector<string>& ar,string& s,int l,int r)
    {
        if(l>=r)
        ar.push_back(s);
        else
        {
            for(int i=l;i<=r;i++)
            {
                char t=s[l];
                s[l]=s[i];
                s[i]=t;
                solve(ar,s,l+1,r);
                t=s[l];
                s[l]=s[i];
                s[i]=t;
            }
        }
    }
    vector<string> permutation(string S)
    {
        //Your code here
        vector<string> ans;
        solve(ans,S,0,S.size()-1);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends
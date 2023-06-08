//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	int bin(string& ans,int ele,int l,int r)
{
   while(l<=r)
   {
       int mid=(l+r)/2;
       if(ele<ans[mid])
       l=mid+1;
       else
       r=mid-1;
   }
   return l-1;
}
void reverse(int l,int r,string& a)
{
    while(l<=r)
    {
        int t=a[l];
        a[l]=a[r];
        a[r]=t;
        l++;
        r--;
    }
}
void next(string& c)
{
    int n=c.size();
    int i=n-2;
    while(i>=0&&c[i]>=c[i+1])
    i--;
    if(i<0)
    {
        sort(c.begin(),c.end());
    }
    else
    {
        int idx=(bin(c,c[i],i+1,n-1));
        int t=c[idx];
        c[idx]=c[i];
        c[i]=t;
        reverse(i+1,n-1,c);
        
    }
}
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    vector<string> ans;
		    int n=S.size();
		    int f=1;
		  //  for(int i=1;i<=n;i++)
		  //  f*=i;
		    sort(S.begin(),S.end());
		     ans.push_back(S);
		   while(1)
		    {
	          next(S);
	       //   cout<<S<<endl;
		      if(S==ans[0])
		      break;
		      ans.push_back(S);
		       
		    }
		    return ans;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends
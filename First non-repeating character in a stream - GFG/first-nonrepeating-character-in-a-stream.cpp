//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    unordered_map<int,int> m1;
		    vector<int> valid(26,1);
		    queue<int> q;
		    string ans;
		    int x=0;
		    for(int i=0;i<A.size();i++)
		    {
		        char it=A[i];
		        m1[it]++;
		        if(m1[it]==1)
		         q.push(it);
		        else
		        valid[it-'a']=-1;
		        int flg=-1;
		        while(!q.empty())
		        {
		            if(valid[q.front()-'a']==1)
		            {
		            ans+=q.front();
		            flg=1;
		            break;
		            }
		            else
		            q.pop();
		        }
		        if(flg==-1)
		        ans+='#';
		    }
		    return ans;
		}
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
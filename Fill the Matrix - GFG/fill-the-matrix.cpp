//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int minIteration(int N, int M, int x, int y){    
        // code here
        vector<vector<int>> m(N,vector<int>(M,0));
        m[x-1][y-1]=1;
        queue<pair<int,int>>q;
        q.push({x-1,y-1});
        int ans=0;
        while(!(q.empty()))
    {
        int s=q.size();
        while(s--)
        {
            pair<int,int> tmp=q.front();
            q.pop();
            int xx=tmp.first;
            int yy=tmp.second;
            if(xx-1>=0&&m[xx-1][yy]==0)
            {
            m[xx-1][yy]=1;
            q.push({xx-1,yy});
            }
         if(xx+1<N&&m[xx+1][yy]==0)
            {
            m[xx+1][yy]=1;
         q.push({xx+1,yy});
        }
         if(yy+1<M&&m[xx][yy+1]==0)
            {
            m[xx][yy+1]=1;
            q.push({xx,yy+1});
        }
         if(yy-1>=0&&m[xx][yy-1]==0)
            {
            m[xx][yy-1]=1;
            q.push({xx,yy-1});
        }
        }
        ans++;
    }
      return ans-1;  
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M, x, y;
        cin >> N >> M;
        cin >> x >> y;
        
        Solution ob;
        cout << ob.minIteration(N, M, x, y) << endl;
    }
    return 0; 
} 
// } Driver Code Ends
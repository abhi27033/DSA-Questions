//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
bool solve(vector<vector<char>>& mat,int i,int j,vector<vector<int>>& vis)
{
    int n=mat.size(),m=mat[0].size();
    if(i<0||j<0||i>=n||j>=m)
    return false;
    if(vis[i][j]==1||mat[i][j]=='X')
    return true;
    vis[i][j]=1;
    bool a=solve(mat,i+1,j,vis);
    bool b=solve(mat,i,j+1,vis);
    bool c=solve(mat,i-1,j,vis);
    bool d=solve(mat,i,j-1,vis);
    return a&&b&&c&&d;
}
void sol(vector<vector<char>>& mat,int i,int j)
{
    int n=mat.size(),m=mat[0].size();
    if(i<0||j<0||i>=n||j>=m||mat[i][j]=='X')
    return;
    mat[i][j]='X';
    sol(mat,i+1,j);
    sol(mat,i,j+1);
    sol(mat,i-1,j);
    sol(mat,i,j-1);
}
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        vector<vector<int>> vis(n,vector<int>(m,-1));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]=='O'&&vis[i][j]==-1)
                {
                    //  vector<vector<int>> vis(n,vector<int>(m,-1));
                    bool a=solve(mat,i,j,vis);
                    if(a)
                    {
                        
                        // for(auto it:vis)
                        // {
                        //     for(auto itt:it)
                        //     cout<<itt<<" ";
                        //     cout<<endl;
                        // }
                        // cout<<"-----"<<endl;
                        // cout<<i<<j<<endl;
                    sol(mat,i,j);
                    }
                }
            }
        }
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends
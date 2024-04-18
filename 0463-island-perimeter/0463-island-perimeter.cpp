class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& vis)
    {
        if(i<0||j<0||i>=grid.size()||j>=grid[0].size()||grid[i][j]==0)
            return 1;
        if(vis[i][j]==1)return 0;
        vis[i][j]=1;
        return solve(i+1,j,grid,vis)+solve(i,j+1,grid,vis)+solve(i-1,j,grid,vis)+solve(i,j-1,grid,vis);
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,-1));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j])
                    return solve(i,j,grid,vis);
            }
        }
        return 0;
    }
};
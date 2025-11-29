class Solution {
public:
int m=1e9+7;
vector<vector<vector<int>>> dp;
int solve(vector<vector<int>>& grid, int i,int j,int& k,int s){
    if(i>=grid.size()||j>=grid[0].size()||i<0||j<0)return 0;
    if(i==grid.size()-1&&j==grid[0].size()-1){
        s=(s%k+grid[i][j])%k;
        return (s==0);
    }
    if(dp[i][j][s]!=-1)return dp[i][j][s];
    return dp[i][j][s]=(solve(grid,i+1,j,k,(s%k+grid[i][j]%k)%k)%m+solve(grid,i,j+1,k,(s%k+grid[i][j]%k)%k)%m)%m;
}
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        dp.resize(grid.size(),vector<vector<int>>(grid[0].size(),vector<int>(k+1,-1)));
        return solve(grid,0,0,k,0)%m;
    }
};
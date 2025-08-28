class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        for(int i=0;i<n+n-1;i++){
            if(i>=n){
                int ii=0;
                int jj=i-n+1;
                vector<int> q;
                int ti=ii,tj=jj;
                while(ti<n&&tj<n)
                    q.push_back(grid[ti++][tj++]);
                ti=ii,tj=jj;
                int f=0;
                sort(q.begin(),q.end());
                while(ti<n&&tj<n)
                    grid[ti++][tj++]=q[f++];
            }
            else{
                int ii=n-i-1;
                int jj=0;
                vector<int> q;
                int ti=ii,tj=jj;
                while(ti<n&&tj<n)
                    q.push_back(grid[ti++][tj++]);
                ti=ii,tj=jj;
                int f=0;
                sort(q.rbegin(),q.rend());
                while(ti<n&&tj<n)
                    grid[ti++][tj++]=q[f++];
            }
        }
        return grid;
    }
};
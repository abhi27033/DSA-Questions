class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n=grid.size(),ii,jj;
        for(int i=0;i<n+n-1;i++){
            if(i>=n){
                ii=0;
                jj=i-n+1;
            }
            else{
                ii=n-i-1;
                jj=0;
            }
            vector<int> q;
            int ti=ii,tj=jj;
            while(ti<n&&tj<n)
                q.push_back(grid[ti++][tj++]);
            ti=ii,tj=jj;
            int f=0;
            if(i>=n)
                sort(q.begin(),q.end());
            else
                sort(q.rbegin(),q.rend());
            while(ti<n&&tj<n)
                grid[ti++][tj++]=q[f++];
        }
        return grid;
    }
};
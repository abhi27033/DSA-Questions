class Solution {
public:
    vector<vector<int>> ans;
    int mini,minj,maxi,maxj;
    void dfs(vector<vector<int>>& ar,int i,int j)
    {
        int n=ar.size(),m=ar[0].size();
        if(i<0||j<0||i>=n||j>=m||ar[i][j]==0)
        {
            mini=min(mini,i);
            maxi=max(maxi,i);
            minj=min(minj,j);
            maxj=max(maxj,j);
            return;
        }
        ar[i][j]=0;
        dfs(ar,i+1,j);
        dfs(ar,i-1,j);
        dfs(ar,i,j-1);
        dfs(ar,i,j+1);
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n=land.size(),m=land[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(land[i][j])
                {
                    mini=INT_MAX,minj=INT_MAX,maxi=-1,maxj=-1;
                    dfs(land,i,j);
                     mini++;
                    minj++;
                    maxi--;
                    maxj--;
                    ans.push_back({mini,minj,maxi,maxj});
                }
            }
        }
        return ans;
    }
};
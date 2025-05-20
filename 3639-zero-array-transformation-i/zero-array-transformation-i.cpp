class Solution {
public:
bool solve(int m,vector<vector<int>>& q,vector<int>& nums)
{
    int n=nums.size();
    vector<int> ps(n+1,0);
    for(int i=0;i<m;i++)
    {
        ps[q[i][0]]+=1;
        ps[q[i][1]+1]-=1;
    }
    for(int i=1;i<=n;i++)
    ps[i]+=ps[i-1];
    for(int i=0;i<n;i++)
    if(nums[i]>ps[i])return false;
    return true;
}
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int ans=-1,l=0,r=queries.size();
        return solve(r,queries,nums);
        // while(l<=r)
        // {
        //     int m=l+(r-l)/2;
        //     if(solve(m,queries,nums))
        //     {
        //         ans=m;
        //         r=m-1;
        //     }
        //     else
        //     l=m+1;
        // }
        return ans;
    }
};
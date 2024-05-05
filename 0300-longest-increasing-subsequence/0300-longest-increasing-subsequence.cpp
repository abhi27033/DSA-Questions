class Solution {
public:
    vector<int> dp;
    int glans=1;
    int solve(vector<int>& ar,int idx)
    {
        if(idx>=ar.size())return 0;
        if(dp[idx]!=-1)return dp[idx];
        int ele=ar[idx];
        int ans=1;
        for(int i=idx+1;i<ar.size();i++)
        {
            if(ar[i]>ele)
            ans=max(ans,1+solve(ar,i));
        }
        glans=max(glans,ans);
        glans=max(glans,solve(ar,idx+1));
        return dp[idx]=ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        dp.resize(n+1,-1);
        solve(nums,0);
        return glans;
    }
};
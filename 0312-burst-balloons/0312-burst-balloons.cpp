class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int>& ar,int l,int h)
    {
        //burst the last ballon
        if(l>h)
            return 0;
        int ans=INT_MIN;
        if(dp[l][h]!=-1)
            return dp[l][h];
        for(int i=l;i<=h;i++)
        {
            int t=ar[i];
            t*=ar[h+1];
            t*=ar[l-1];
            t+=solve(ar,l,i-1);
            t+=solve(ar,i+1,h);
            ans=max(ans,t);
        }
        return dp[l][h]=ans;
    }
    int maxCoins(vector<int>& nums) {
        vector<int> t;
        t.push_back(1);
        for(auto it:nums)
            t.push_back(it);
        t.push_back(1);
        dp.resize(t.size()+1,vector<int>(t.size()+1,-1));
        return solve(t,1,nums.size());
    }
};

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
        dp.resize(t.size()+1,vector<int>(t.size()+1,0));
        // return solve(t,1,nums.size());
        for(int l=nums.size();l>=1;l--)
        {
            for(int h=l;h<=nums.size();h++)
            {
                int ans=INT_MIN;
                for(int k=l;k<=h;k++)
                {
                    int test=t[k];
                    test*=t[h+1];
                    test*=t[l-1];
                    test+=dp[l][k-1];
                    test+=dp[k+1][h];
                    ans=max(ans,test);
                }
                dp[l][h]=ans;
            }
        }
        return dp[1][nums.size()];
    }
};

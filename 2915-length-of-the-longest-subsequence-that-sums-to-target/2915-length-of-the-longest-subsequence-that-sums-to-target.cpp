class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int>& ar,int t,int i)
    {
        if(t==0)return 0;
        if(i>=ar.size()||t<0)return -1e6;
        if(dp[i][t]!=-1)return dp[i][t];
        int pick=1+solve(ar,t-ar[i],i+1);
        int npick=solve(ar,t,i+1);
        return dp[i][t]=max(pick,npick);
    }
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n=nums.size();
        dp.resize(n+1,vector<int>(target+1,-1));
        int x=solve(nums,target,0);
        return x<0?-1:x;
    }
};
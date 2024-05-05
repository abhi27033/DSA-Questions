class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int>& ar,int idx,int amt)
    {
        if(idx>=ar.size()||amt<0)return 1e7;
        if(amt==0)return 0;
        if(dp[idx][amt]!=-1)return dp[idx][amt];
        int pick=1+solve(ar,idx,amt-ar[idx]);
        int npick=solve(ar,idx+1,amt);
        return dp[idx][amt]=min(pick,npick);        
    }
    int coinChange(vector<int>& coins, int amount) {
        dp.resize(coins.size()+1,vector<int>(amount+1,-1));
        int ans= solve(coins,0,amount);
        if(ans>=1e7)return -1;
        return ans;
    }
};
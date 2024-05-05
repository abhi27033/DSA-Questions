class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int>& ar,int i,int amt)
    {
        if(i>=ar.size()||amt<0)return 0;
        if(amt==0)return 1;
        if(dp[i][amt]!=-1)return dp[i][amt];
        int pick=solve(ar,i,amt-ar[i]);
        int npick=solve(ar,i+1,amt);
        return dp[i][amt]=pick+npick;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        dp.resize(n+1,vector<int>(amount+1,-1));
        return solve(coins,0,amount);
    }
};
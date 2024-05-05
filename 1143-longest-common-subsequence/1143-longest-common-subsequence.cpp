class Solution {
public:
    vector<vector<int>> dp;
    int solve(string& t1,string& t2,int i,int j)
    {
        if(i>=t1.size()||j>=t2.size())return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(t1[i]==t2[j])return 1+solve(t1,t2,i+1,j+1);
        return dp[i][j]=max(solve(t1,t2,i+1,j),solve(t1,t2,i,j+1));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size(),m=text2.size();
        dp.resize(n+1,vector<int>(m+1,-1));
        return solve(text1,text2,0,0);
    }
};
class Solution {
public:
    int dp[101][101];
    bool solve(string& s,int i,int a)
    {
        if(i==s.size())
            return a==0;
        if(a<0)return false;if(dp[i][a]!=-1)return dp[i][a];
        if(s[i]=='*')
            return dp[i][a]=solve(s,i+1,a+1)||solve(s,i+1,a-1)||solve(s,i+1,a);
        else if(s[i]=='(')
        return dp[i][a]=solve(s,i+1,a+1);
        return dp[i][a]=solve(s,i+1,a-1);
    }
    bool checkValidString(string s) {
        memset(dp,-1,sizeof(dp));
        return solve(s,0,0);
    }
};
class Solution {
public:
vector<long long> dp;
    long long solve(vector<vector<int>>& q,int i)
    {
        if(i>=q.size())return 0;
        if(dp[i]!=-1)return dp[i];
        long long pick=q[i][0]+solve(q,i+q[i][1]+1);
        long long npick=solve(q,i+1);
        return dp[i]=max(pick,npick);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        dp.resize(n,-1);
        return solve(questions,0);
    }
};
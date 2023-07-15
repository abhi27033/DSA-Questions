class Solution {
public:
    int solve(vector<vector<int>>& events,int idx,int k, vector<vector<int>>& dp)
    {
        if(idx>=events.size()||k==0)
            return 0;
        if(dp[idx][k]!=-1)
            return dp[idx][k];
        int a=solve(events,idx+1,k,dp);
        int flg=-1;
        for(int i=idx+1;i<events.size();i++)
        {
            if(events[idx][1]<events[i][0])
            {
                flg=i;
                break;
            }
        }
        int b=events[idx][2];
        if(flg!=-1)
            b+=solve(events,flg,k-1,dp);
        return dp[idx][k]=max(a,b);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(),events.end());
        vector<vector<int>> dp(events.size()+1,vector<int>(k+1,-1));
        return solve(events,0,k,dp);
    }
};
class Solution {
public:
    vector<vector<int>> dp;
    // int solve(string& s,int idx,int pidx,int& k)
    // {
    //     if(idx>=s.size())return 0;
    //     if(dp[idx][pidx+1]!=-1)return dp[idx][pidx+1];
    //     int a=0,b=0;
    //     if(pidx==-1||abs(s[pidx]-s[idx])<=k)
    //         a=1+solve(s,idx+1,idx,k);
    //     b=solve(s,idx+1,pidx,k);
    //     return dp[idx][pidx+1]=max(a,b);
    // }
    int longestIdealString(string s, int k) {
        vector<int> mp(26,0);
        for(int i=0;i<s.size();i++)
        {
            char ch=s[i];
            int x=ch-'a';
            int c=0;
            for(int j=max(x-k,0);j<=min(x+k,25);j++)
            c=max(c,mp[j]);
            mp[x]=c+1;
        }
        int ans=INT_MIN;
        for(auto it:mp)
            ans=max(ans,it);
        return ans;
    }
};
class Solution {
public:
    int palinconvert(string& s,int a,int b)
    {
        if(a>b)
            return 0;
        return !(s[a]==s[b])+palinconvert(s,a+1,b-1);
    }
    vector<vector<vector<int>>> dp;
    int solve(string& s,int i,int pidx,int k)
    {
        if(i>=s.size())
        {
            if(k==0)
                return 0;
            return 100001;
        }
        if(k==0)
            return 100001;
        if(dp[i][pidx][k]!=-1)
            return dp[i][pidx][k];
        int cnt=100001,d=100001;
        cnt=palinconvert(s,pidx,i);
        cnt+=solve(s,i+1,i+1,k-1);
        d=solve(s,i+1,pidx,k);
        // cout<<i<<" "<<pidx<<" "<<cnt<<" "<<d<<" "<<k<<endl;
        return dp[i][pidx][k]=min(cnt,d);
    }
    int palindromePartition(string s, int k) {
        int n=s.size()+1;
        dp.resize(n,vector<vector<int>>(n,vector<int>(k+1,-1)));
        return solve(s,0,0,k);
    }
};
class Solution {
public:
vector<vector<bool>> palin; 
int dp[2001];
void genpalin(string s)
{   
    palin.resize(s.size(),vector<bool>(s.size(),false));
    for(int i=0;i<s.size();i++)
    {
        int l=i,r=i+1;
        while(l>=0&&r<s.size())
        {
            if(s[l]!=s[r])break;
            palin[l][r]=true;
            palin[r][l]=true;
            l++;
            r--;
        }
        l=i,r=i;
        while(l>=0&&r<s.size())
        {
            if(s[l]!=s[r])break;
            palin[l][r]=true;
            palin[r][l]=true;
            l++;
            r--;
        }
    }
}
int solve(string& s,int i){
    if(i>=s.size())return 0;
    if(dp[i]!=-1)return dp[i];
    int ans=s.size();
    for(int j=i;j<s.size();j++)
    {
        if(palin[i][j])
            ans=min(ans,1+solve(s,j+1));   
    }
    return dp[i]=ans;
}
    int minCut(string s) {
        memset(dp,-1,sizeof(dp));
        genpalin(s);
        return solve(s,0)-1;
    }
};
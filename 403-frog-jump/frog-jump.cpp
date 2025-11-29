class Solution {
public:
int dp[2001][2001];
int exists(vector<int>& st,int l,int val){
    int r=st.size()-1;
    while(l<=r){
        int m=l+(r-l)/2;
        if(st[m]==val)return m;
        if(st[m]<val)
        l=m+1;
        else
        r=m-1;
    }
    return -1;
}
bool solve(vector<int>& st,int i,int k){
    if(i==st.size()-1)
    return true;
    if(dp[i][k]!=-1)return dp[i][k];
    bool ans=false;
    int a=exists(st,i+1,st[i]+k-1),b=exists(st,i+1,st[i]+k),c=exists(st,i+1,st[i]+k+1);
    if(k>1&&a!=-1)
    ans|=solve(st,a,k-1);
    if(k!=0&&b!=-1)
    ans|=solve(st,b,k);
    if(c!=-1)
    ans|=solve(st,c,k+1);
    return dp[i][k]=ans;
}
    bool canCross(vector<int>& stones) {
        memset(dp,-1,sizeof(dp));
        return solve(stones,0,0);
    }
};
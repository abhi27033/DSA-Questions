class Solution {
public:
int dp[32][2][2];
int solve(vector<int>& bits,int idx,int tight,int past){
    if(idx>=bits.size())return 1;
    if(dp[idx][tight][past]!=-1)return dp[idx][tight][past];
    int limit=1,ans=0;
    if(tight)limit=bits[idx];
    for(int i=0;i<=limit;i++)
    {
        if(past==1&&i==1)break;
        ans+=solve(bits,idx+1,tight&&(i==bits[idx]),i);
    }
    return dp[idx][tight][past]=ans;
}
    int findIntegers(int n) {
        vector<int> bits;
        while(n){
            bits.push_back((n&1));
            n>>=1;
        }
        memset(dp,-1,sizeof(dp));
        reverse(bits.begin(),bits.end());
        return solve(bits,0,1,0);
    }
};
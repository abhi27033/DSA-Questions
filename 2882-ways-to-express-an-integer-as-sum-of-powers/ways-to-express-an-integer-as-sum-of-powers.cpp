class Solution {
public:
int mod=1e9+7;
int power(int b, int e){
    int t=1;
    while(e>=1){
        if(e&1)
        {
            t=(t%mod*b%mod)%mod;
            e--;
        }
        else
        {
            b=(b%mod*b%mod)%mod;
            e/=2;
        }
    }
    return t%mod;
}
vector<vector<int>> ar;
int solve(int n,int i,int& x){
    if(n==0)return 1;
    if(n<0||power(i,x)>n)return 0;
    if(ar[n][i]!=-1)return ar[n][i]%mod;
    return ar[n][i]=solve(n,i+1,x)%mod+solve(n-power(i,x),i+1,x)%mod;
}
    int numberOfWays(int n, int x) {
        ar.resize(n+1,vector<int>(n+1,-1));
        return solve(n,1,x)%mod;
    }
};
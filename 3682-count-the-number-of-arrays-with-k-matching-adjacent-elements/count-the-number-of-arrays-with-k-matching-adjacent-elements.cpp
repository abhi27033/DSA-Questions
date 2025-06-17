class Solution {
public:
long long MOD=1e9+7;
    long long inv(long long base,long long pow){
        long long ans=1;
        while(pow)
        {
            if(pow&1)
                ans=(ans%MOD*base%MOD)%MOD;
            base=((base%MOD)*(base%MOD))%MOD;
            pow>>=1LL;
        }
        return ans;
    }
    long long nck(int n,int k){
        long long ans=1;
        if(k==0)return ans;
        for(long long i=k+1;i<=n;i++)
        ans=(ans%MOD*i%MOD)%MOD;
        long long den=1;
        for(long long i=2;i<=(n-k);i++)
        den=(den%MOD*i%MOD)%MOD;
        den=inv(den,MOD-2);
        ans=(ans%MOD*den%MOD)%MOD;
        return ans;
    }
    int countGoodArrays(int n, int m, int k) {
        //Stars and Bars
        //       |*|*|
        //n-1 places (spaces) k equals ,i.e. (n-1)C(k)
        //Do this for all m
        if(m==1&&n-k>1)return 0LL;
        long long stars_and_bars=nck(n-1,k);
        stars_and_bars=(stars_and_bars%MOD*m%MOD)%MOD;
        long long rest=inv(m-1,n-1-k)%MOD;
        stars_and_bars=(stars_and_bars%MOD*rest%MOD)%MOD;
        return (int)stars_and_bars;
    }
};
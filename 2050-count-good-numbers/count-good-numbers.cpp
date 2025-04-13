class Solution {
public:
int m=1e9+7;
long long power(long long b, long long e){
    long long ans=1;
    while(e>=1){
        if(e&1)
        {
            ans=(ans%m*b%m)%m;
            e--;
        }
        else{
            b=(b%m*b%m)%m;
            e/=2;
        }
    }
    return ans%m;
}
    int countGoodNumbers(long long n) {
        long long f=(n+1)/2;
        long long ff=n/2;
        long long fa=power(5LL,f);
        long long ffa=power(4LL,ff);
        return (fa%m*ffa%m)%m;
    }
};
class Solution {
public:
    int numTilings(int n) {
       long dp[1200];
       dp[0]=1;
       dp[1]=2;
       dp[2]=5;
       for(int i=3;i<1200;i++)
       {
       dp[i]=2*dp[i-1]+dp[i-3];
    dp[i]%=1000000007;
       }
       return dp[n-1]%1000000007; 
    }
};
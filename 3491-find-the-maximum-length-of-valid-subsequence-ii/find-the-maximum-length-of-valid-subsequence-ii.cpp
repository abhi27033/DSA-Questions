class Solution {
public:
int dp[1001][2][2];
// vector<vector<vector<int>>> dp;
// vector<vector<int>> nex;
//     int solve(vector<int>& nums,int i,int c,int p,int& s,int& k){
//         if(i>=nums.size())return 0;
//         if(dp[i][c][p]!=-1)return dp[i][c][p];
//         int pick=1,npick=0;
//         int nexx=nums[i];
//         if(c==0)
//         nexx=s-nexx;
//         else
//         {
//             nexx*=-1;
//             nexx+=s;
//         }
//         nexx = ((nexx % k) + k) % k;  
//         if(nex[i][nexx]!=-1)
//         pick=1+solve(nums,nex[i][nexx],1-c,1,s,k);
//         if(p==0)
//         npick=solve(nums,i+1,c,p,s,k);
//         return dp[i][c][p]=max(pick,npick);
//     }
    int maximumLength(vector<int>& nums, int k) {
        for(auto& it:nums)it%=k;
        // for(auto it:nums)cout<<it<<" ";
        int n=nums.size(),ans=1;
        vector<vector<int>> nex(n, vector<int>(k, -1));
        vector<int> last(k, -1);
        for (int i = n-1; i >= 0; --i) {
            nex[i] = last;
            last[ nums[i] ] = i;
        }
        for(int i=0;i<=k;i++){
        // vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(2,-1)));
        memset(dp, -1, sizeof dp);
        dp[n-1][0][0]=0,dp[n-1][0][1]=0,dp[n-1][1][0]=0,dp[n-1][1][1]=0;
        for(int j=n-1;j>=0;j--){
            for(int kk=1;kk>=0;kk--){
                for(int l=1;l>=0;l--){
                    int pick=1,npick=0;
                    int nexx=nums[j];
                    if(kk==0)
                    nexx=i-nexx;
                    else
                    {
                        nexx*=-1;
                        nexx+=i;
                    }
                    nexx = ((nexx % k) + k) % k;  
                    if(nex[j][nexx]!=-1)
                    pick=1+dp[nex[j][nexx]][1-kk][1];
                    if(l==0&&j+1<n)
                    npick=dp[j+1][kk][l];
                    dp[j][kk][l]=max(pick,npick);
                }
            }
        }
        int t=dp[0][0][0];
        ans=max(ans,t);
        }
        return ans;
    }
};
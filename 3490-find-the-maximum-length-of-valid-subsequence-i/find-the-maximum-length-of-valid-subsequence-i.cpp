class Solution {
public:
vector<vector<vector<int>>> dp;
    int solve(vector<int>& nums,int i,int c,int cs,int& s){
        if(i>=nums.size()){
            if(c!=0)return 0;return -1e9;
        }
        if(dp[i][c][cs]!=-1)return dp[i][c][cs];
        int npick=solve(nums,i+1,c,cs,s);
        int pick=-1e9;
        if(c==0)
        pick=1+solve(nums,i+1,c+1,nums[i]%2,s);
        else if((cs+nums[i])%2==s)
        pick=1+solve(nums,i+1,1,nums[i]%2,s);
        return dp[i][c][cs]=max(pick,npick);
    }
    int maximumLength(vector<int>& nums) {
        int n=nums.size();
        dp.resize(n,vector<vector<int>>(2,vector<int>(3,-1)));
        int a=0,b=1,c=2;
        int ans=0;
        ans=max(ans,solve(nums,0,0,0,a));
        for(int i=0;i<n;i++)
        {
            dp[i][0][0]=-1;
            dp[i][0][1]=-1;
            dp[i][0][2]=-1;
            dp[i][1][0]=-1;
            dp[i][1][1]=-1;
            dp[i][1][2]=-1;
        }
        ans=max(ans,solve(nums,0,0,0,b));
        for(int i=0;i<n;i++)
        {
            dp[i][0][0]=-1;
            dp[i][0][1]=-1;
            dp[i][0][2]=-1;
            dp[i][1][0]=-1;
            dp[i][1][1]=-1;
            dp[i][1][2]=-1;
        }
        ans=max(ans,solve(nums,0,0,0,c));
        return ans;
    }
};
class Solution {
public:
vector<vector<vector<int>>> dp;
int m=1e9+7;
int solve(vector<int>& nums,int i,int p1,int p2){
    if(i>=nums.size())return 1;
    if(dp[i][p1+1][p2+1]!=-1)return dp[i][p1+1][p2+1]%m;
    long long ans=solve(nums,i+1,p1,p2)%m;
    if(p2==-1)
    ans=(ans%m+solve(nums,i+1,p2,nums[i]%2)%m)%m;
    else{
        int p=nums[i]%2;
        if(!(p1==p2&&p2==p))
        ans=(ans%m+solve(nums,i+1,p2,p)%m)%m;
    }
    return dp[i][p1+1][p2+1]=ans%m;
}
    int countStableSubsequences(vector<int>& nums) {
        dp.resize(nums.size(),vector<vector<int>>(3,vector<int>(3,-1)));
        return solve(nums,0,-1,-1)-1;
    }
};
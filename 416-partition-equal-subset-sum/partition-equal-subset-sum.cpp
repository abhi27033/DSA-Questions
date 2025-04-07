class Solution {
public:
vector<vector<int>> dp;
int solve(vector<int>& nums,int i,int s,int& sum){
    if(i>=nums.size())return sum==(s*2);
    if(dp[i][s]!=-1)return dp[i][s];
    return dp[i][s]=solve(nums,i+1,s+nums[i],sum)||solve(nums,i+1,s,sum);
}
    bool canPartition(vector<int>& nums) {
        int s=0;
        for(auto it:nums)s+=it;
        if(s&1)return false;
        dp.resize(nums.size(),vector<int>(s+1,-1));
        return solve(nums,0,0,s);
    }
};
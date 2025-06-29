class Solution {
public:
vector<vector<int>> dp;
int solve(vector<int>& nums,int k,int idx){
    if(k==1){
        int x=0;
        for(int i=idx;i<nums.size();i++)
        x^=nums[i];
        return x;
    }
    if(dp[idx][k]!=-1)return dp[idx][k];
    int x=0,ans=INT_MAX;
    for(int i=idx;i<=nums.size()-k;i++){
        x^=nums[i];
        ans=min(ans,max(x,solve(nums,k-1,i+1)));
    }
    return dp[idx][k]=ans;
}
    int minXor(vector<int>& nums, int k) {
        dp.resize(nums.size(),vector<int>(k+1,-1));
        return solve(nums,k,0);
    }
};
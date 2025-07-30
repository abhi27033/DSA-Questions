class Solution {
public:
vector<int> dp;
bool solve(vector<int>& nums,int i,int mask,int k,int cs,int& rs){
    if(k==0)return cs==0&&(mask==(1<<nums.size())-1);
    if(cs>rs)return false;
    if(dp[mask]!=-1)return dp[mask];
    if(cs==rs)return dp[mask]=solve(nums,0,mask,k-1,0,rs);
    for(int st=0;st<nums.size();st++){
        if(mask>>st&1)continue;
        if(solve(nums,st+1,mask|(1<<st),k,cs+nums[st],rs))return dp[mask]=true;
    }
    return dp[mask]=false;
    
}
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int s=0;
        for(auto it:nums)s+=it;
        if(s%k!=0)return false;
        sort(nums.begin(),nums.end());
        int reqsum=s/k,n=nums.size();
        dp.resize(1<<(n+1),-1);
        return solve(nums,0,0,k,0,reqsum);
    }
};
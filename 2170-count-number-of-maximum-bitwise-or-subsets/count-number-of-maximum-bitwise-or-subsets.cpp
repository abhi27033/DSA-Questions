class Solution {
public:
    int solve(vector<int>& nums,int i,int orr,int& x)
    {
        if(i>=nums.size())
        return orr==x;
        int pick=solve(nums,i+1,(orr|nums[i]),x);
        int npick=solve(nums,i+1,orr,x);
        return pick+npick;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int x=0;
        for(auto it:nums)
        x|=it;
        return solve(nums,0,0,x);
    }
};
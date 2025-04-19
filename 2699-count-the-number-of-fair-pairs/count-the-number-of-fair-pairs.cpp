class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        long long ans=0;
        for(int i=0;i<nums.size();i++)
        {
            int low=lower-nums[i];
            int high=upper-nums[i];
            int li=lower_bound(nums.begin()+i+1,nums.end(),low)-nums.begin();
            int hi=upper_bound(nums.begin()+i+1,nums.end(),high)-nums.begin();
            int diff=hi-li;
            ans+=diff;
        }
        return ans;
    }
};
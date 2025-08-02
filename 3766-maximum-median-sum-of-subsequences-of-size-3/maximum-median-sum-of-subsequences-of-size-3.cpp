class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size()/3;
        long long ans=0;
        for(int i=nums.size()-2;n--;i-=2)
        ans+=nums[i];
        return ans;
    }
};
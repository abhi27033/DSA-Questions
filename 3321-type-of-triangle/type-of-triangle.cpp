class Solution {
public:
    string triangleType(vector<int>& nums) {
        return ((nums[0]+nums[1]<=nums[2]||nums[1]+nums[2]<=nums[0]||nums[2]+nums[0]<=nums[1])?"none":((nums[0]==nums[1]&&nums[1]==nums[2])?"equilateral":((nums[0]!=nums[1]&&nums[1]!=nums[2]&&nums[0]!=nums[2])?"scalene":"isosceles")));
    }
};
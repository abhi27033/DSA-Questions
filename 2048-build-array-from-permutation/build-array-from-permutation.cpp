class Solution {
public:
    vector<int> buildArray(vector<int>& nums) 
    {
        for(auto& item : nums) item |= nums[item & 0xFFFF] << 16; //item & 0xFFFF ensures take only lower 16 bits
        for(auto& item : nums) item >>= 16;
        return nums;
    }
};
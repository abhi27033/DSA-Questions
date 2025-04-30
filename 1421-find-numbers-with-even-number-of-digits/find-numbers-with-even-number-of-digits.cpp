class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int c=0;
        for(auto it:nums)
        if(((int)log10(it))%2)c++;
        return c;
    }
};
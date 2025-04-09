class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int start = -1, end = -1;
        int max_seen = INT_MIN, min_seen = INT_MAX;
        for (int i = 0; i < n; ++i) {
            if (nums[i] < max_seen)
                end = i;
            else
                max_seen = nums[i];
        }
        for (int i = n - 1; i >= 0; --i) {
            if (nums[i] > min_seen)
                start = i;
            else
                min_seen = nums[i];
        }

        return (end == -1) ? 0 : (end - start + 1);
    }
};

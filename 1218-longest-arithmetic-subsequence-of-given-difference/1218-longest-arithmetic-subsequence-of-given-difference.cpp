class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> memo;
        int ans = 0;
        
        for (int i = 0; i < arr.size(); i++) {
            int curr = arr[i];
            int prev = curr - difference;
            int subResult = memo[prev] + 1;
            memo[curr] = subResult;
            ans = max(ans, subResult);
        }
        
        return ans;
    }
};

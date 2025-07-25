class Solution {
public:
    int maxSum(vector<int>& num) {
        unordered_set<int> nums;
        int ans=INT_MIN;
        for(auto it:num){
            if(it>0)
            nums.insert(it);
            ans=max(ans,it);
        }
        if(nums.size()==0)
        return ans;
        ans=0;
        for(auto it:nums)ans+=it;
        return ans;
    }
};
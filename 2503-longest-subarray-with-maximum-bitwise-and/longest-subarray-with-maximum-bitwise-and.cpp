class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ma=INT_MIN;
        for(auto it:nums)
        ma=max(ma,it);
        int c=0,ans=0;
        for(auto it:nums){
            if(it!=ma)c=0;
            else c++;
            ans=max(ans,c);
        }
        return ans;
    }
};
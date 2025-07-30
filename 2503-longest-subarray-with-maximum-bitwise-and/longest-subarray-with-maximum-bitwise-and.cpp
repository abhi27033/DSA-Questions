class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ma=INT_MIN;
        int c=0,ans=0;
        for(auto it:nums){
            if(ma<it){
                ma=it;
                c=0;
                ans=INT_MIN;
            }
            if(it!=ma)c=0;
            else c++;
            ans=max(ans,c);
        }
        return ans;
    }
};
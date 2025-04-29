class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int ma=INT_MIN;
        for(auto it:nums)ma=max(ma,it);
        int l=0,cnt=0;
        long long ans=0;
        for(int r=0;r<nums.size();r++){
            if(nums[r]==ma)cnt++;
            while(cnt>=k){
                ans+=(nums.size()-r);
                if(nums[l]==ma)
                    cnt--;
                l++;
            }
        }
        return ans;
    }
};
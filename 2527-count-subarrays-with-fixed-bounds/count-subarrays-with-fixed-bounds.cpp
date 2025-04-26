class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int latest_min=-1,latest_max=-1,latest_out=-1;
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==maxK)
            latest_max=i;
            if(nums[i]==minK)
            latest_min=i;
            if(minK>nums[i]||nums[i]>maxK)
            latest_out=i;
            if(minK<=nums[i]&&nums[i]<=maxK)
            {
                int q=min(latest_max,latest_min);
                if(q==-1)continue;
                int diff=q-latest_out;
                ans+=max(0,diff);
            }
        }
        return ans;
    }
};
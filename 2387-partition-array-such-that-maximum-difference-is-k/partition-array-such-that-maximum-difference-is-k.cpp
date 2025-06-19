class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int ans=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            int j=i;
            int end=nums[i]+k;
            while(j<nums.size()&&nums[j]<=end)
            j++;
            i=j-1;
            ans++;
        }
        return ans;
    }
};
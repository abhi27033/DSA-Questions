class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        vector<int> leftmax(nums.size()),rightmax(nums.size());
        int n=nums.size();
        leftmax[0]=nums[0];
        rightmax[n-1]=nums[n-1];
        for(int i=1;i<nums.size();i++)leftmax[i]=max(leftmax[i-1],nums[i]);
        for(int i=n-2;i>=0;i--)rightmax[i]=max(rightmax[i+1],nums[i]);
        long long ans=0;
        for(int i=1;i<n-1;i++)
        ans=max(ans,1LL*(1LL*(leftmax[i-1]-nums[i])*rightmax[i+1]));
        return ans;
    }
};
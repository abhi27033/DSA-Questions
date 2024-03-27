class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int p=1;
        int i=0,j=0,n=nums.size(),ans=0;
        while(j<n)
        {
            p*=nums[j];
            while(i<=j&&p>=k)
                p/=nums[i++];
            ans+=(j-i+1);
            j++;
        }
        return ans;
    }
};
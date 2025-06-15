class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        unordered_map<int,int> right;
        for(auto it:nums)right[it]++;
        unordered_map<int,int> left;
        left[nums[0]]++;
        right[nums[0]]--;
        int m=1e9+7,ans=0;
        for(int i=1;i<nums.size()-1;i++)
        {
            right[nums[i]]--;
            int x=nums[i]*2;
            if(left.find(x)!=left.end()&&right.find(x)!=right.end())
            ans=(ans+(1LL*left[x]%m*1LL*right[x]%m)%m)%m;
            left[nums[i]]++;
        }
        return ans;
    }
};
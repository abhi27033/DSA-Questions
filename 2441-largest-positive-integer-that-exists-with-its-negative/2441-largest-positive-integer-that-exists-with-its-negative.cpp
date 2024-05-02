class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_map<int,int> mp,mneg;
        for(auto it:nums)
        {
            if(it>0)
            mp[it]++;
            else
            mneg[abs(it)]++;
        }
        int ans=-1;
        for(auto it:mp)
        {
            if(mneg.find(abs(it.first))!=mneg.end())
                ans=max(ans,it.first);
        }
        return ans;
    }
};
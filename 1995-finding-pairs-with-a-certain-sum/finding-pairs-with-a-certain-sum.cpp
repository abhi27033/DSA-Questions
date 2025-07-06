class FindSumPairs {
public:
unordered_map<int,int> mp;
vector<int> nums1,nums2;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1=nums1;
        this->nums2=nums2;
        mp.clear();
        for(auto it:nums2)
        mp[it]++;
    }
    
    void add(int index, int val) {
        mp[nums2[index]]--;
        nums2[index]+=val;
        mp[nums2[index]]++;
    }
    
    int count(int tot) {
        int ans=0;
        for(auto it:nums1)
        {
            int remain=tot-it;
            if(mp.find(remain)!=mp.end())
            ans+=mp[remain];
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
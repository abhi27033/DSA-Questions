class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        set<int> s;for(auto it:nums)s.insert(it);
        return (distance(s.begin(), s.lower_bound(k))-1)!=-1?-1:s.size()-(s.find(k)!=s.end());
    }
};
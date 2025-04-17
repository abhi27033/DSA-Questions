class Solution {
public:
    long long countPair(vector<int>& nums, int k) {
        // HARD --> https://leetcode.com/problems/count-array-pairs-divisible-by-k/
        unordered_map<int,int> factors;
        int zeroCount=0;
        long long ans=0;
        for(auto it:nums){
            int gcdd=__gcd(it,k);
            int left=k/gcdd;
            if(factors.find(left)!=factors.end())
            ans+=factors[left];
            ans+=zeroCount;
            if(it==0)zeroCount++;
            for(int i=1;i*i<=it;i++){
                if(it%i==0)
                {
                    factors[i]++;
                    if(it/i!=i)
                    factors[it/i]++;
                }
            }
        }
        return ans;
    }
    int countPairs(vector<int>& nums, int k) {
        unordered_map<int,vector<int>> sameCount;
        for(int i=0;i<nums.size();i++){
            sameCount[nums[i]].push_back(i);
        }
        long long ans=0;
        for(auto it:sameCount)
        ans+=countPair(it.second,k);
        return (int)ans;
    }
};
class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        unordered_map<int,int> factors;
        long long ans=0;
        for(auto it:nums){
            int gcdd=__gcd(it,k);
            int left=k/gcdd;
            if(factors.find(left)!=factors.end())
            ans+=factors[left];
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
};
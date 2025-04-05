class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int oor=0;
        for(auto it:nums)
        oor|=it;
        int n=nums.size();
        long long q=(1<<(n-1)),ans=0;
        // int i=0;
        // while(oor)
        // {
        //     ans+=(1<<i)*(oor&1)*q;
        //     i++;
        //     oor>>=1;
        // }
        // https://codeforces.com/blog/entry/112866
        // https://codeforces.com/contest/1614/problem/C
        return oor*q;
    }
};
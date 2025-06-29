class Solution {
public:
long long modpow(long long base,long long exp,long long mod){
    long long ans=1;
    while(exp>0){
        if(exp&1LL)
        {
            ans=(ans*base%mod)%mod;
            exp--;
        }
        else
        {
            base=(base%mod*base%mod)%mod;
            exp>>=1LL;
        }
    }
    return ans%mod;
}
    int numSubseq(vector<int>& nums, int target) {
        int mod=1e9+7,ans=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            int first_num=nums[i];
            int max_adjust=target-first_num;
            if(max_adjust<0)continue;
            int second_num_index=upper_bound(nums.begin(),nums.end(),max_adjust)-nums.begin();
            // cout<<first_num<<" "<<max_adjust<<" "<<second_num_index<<endl;
            long long numbers=second_num_index-i;
            if(numbers>0){
            long long x=modpow(2LL,numbers-1,mod);
            ans=(ans+x%mod)%mod;
            }
        }
        return ans;
    }
};
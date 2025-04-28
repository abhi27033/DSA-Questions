class Solution {
public:
vector<long long> prefix;
int bsearch(int idx,long long k){
    int l=1,r=idx+1,ans=-1;
    while(l<=r){
        int m=l+(r-l)/2;
        long long sum=prefix[idx+1]-prefix[m-1];
        sum*=(idx-m+2);
        if(sum<k)
        {
            ans=m-1;
            r=m-1;
        }
        else
        l=m+1;
    }
    return ans;
}
    long long countSubarrays(vector<int>& nums, long long k) {
        prefix.push_back(0LL);
        for(int i=0;i<nums.size();i++)
        prefix.push_back(prefix.back()+nums[i]*1LL);
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            int idx=bsearch(i,k);
            if(idx!=-1)
            ans+=(i-idx+1);
        }
        return ans;
    }
};

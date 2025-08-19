class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long c=0,ans=0;
        nums.push_back(1);
        for(auto it:nums){
            if(it==0)c++;
            else{
                c*=(c+1);
                c/=2;
                ans+=c;
                c=0;
            }
        }
        return ans;
    }
};
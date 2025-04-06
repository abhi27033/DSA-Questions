class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        unordered_map<int,int> next;
        int n=nums.size();
        vector<int> dp(n,1);
        int ans=1,midx=n-1;
        for(int i=n-2;i>=0;i--){
            int base=nums[i],count=2;
            int q=dp[i];
            for(int j=i+1;j<n;j++){
                if((nums[j]%nums[i]==0)&&(q+dp[j])>=dp[i]){
                    dp[i]=q+dp[j];
                    next[i]=j;
                }
            }
            if(ans<dp[i]){
                ans=dp[i];
                midx=i;
            }
        }
        vector<int> fans;
        fans.push_back(nums[midx]);
        while(next.find(midx)!=next.end())
        {
            midx=next[midx];
            fans.push_back(nums[midx]);
        }
        return fans;
    }
};
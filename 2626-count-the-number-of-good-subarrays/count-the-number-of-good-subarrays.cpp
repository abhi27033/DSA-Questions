class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        long long ans=0,pairs=0;
        int j=0;
        bool flg=false;
        for(int i=0;i<nums.size();i++)
        {
            //add its contribution
            if(mp.find(nums[i])!=mp.end()){
                long long current=mp[nums[i]];
                long long required=current+1;
                current*=(current-1);current/=2;
                required*=(required-1);required/=2;
                pairs-=current;
                pairs+=required;
            }
            mp[nums[i]]++;
            while(j<=i&&pairs>=k)
            {
                //remove pairs with nums[j]
                long long current=mp[nums[j]];
                if(current>1){
                long long required=current-1;
                current*=(current-1);current/=2;
                required*=(required-1);required/=2;
                pairs-=current;
                pairs+=required;
                }
                mp[nums[j]]--;
                j++;
            }
            ans+=j;
        }
        return ans;
    }
};
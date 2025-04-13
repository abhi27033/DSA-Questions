class Solution {
public:
    int minimumRounds(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto it:nums)
        mp[it]++;
        int ans=0;
        for(auto it:mp)
        {
            // cout<<it.first<<" "<<it.second<<endl;
            if(it.second==1)return -1;
            if(it.second%3==0)ans+=(it.second/3);
            else if(it.second%3==1)ans+=((it.second-4)/3)+2;
            else
            {
                if(it.second>=4)
                ans+=((it.second-4)/3+2);
                else
                ans+=(it.second/2);
            }
        }
        return ans;
    }
};
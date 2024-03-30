class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int i=0,n=nums.size(),j=0,ans=0;
        unordered_map<int,int> mp;
        while(j<n)
        {
              mp[nums[j]]++;
             while(i<=j&&mp.size()>k)
            {
                mp[nums[i]]--;
                if(mp[nums[i]]==0)
                    mp.erase(nums[i]);
                i++;
            }
            // cout<<i<<" "<<j<<" "<<mp.size()<<endl;
            if(mp.size()==k)
            {
                int test=i;
                unordered_map<int,int> temp;
                while(test<=j)
                {
                    temp[nums[test]]++;
                    if(mp[nums[test]]==temp[nums[test]])
                        break;
                    test++;
                }
                // cout<<j<<" "<<(test)<<endl;
                ans+=(test-i+1);
            }
           
            j++;
        }
        return ans;
    }
};
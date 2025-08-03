class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(auto it:nums)mp[it]++;
        int fans=0;
        unordered_map<int,int> used;
        for(auto it:mp){
            int x=it.first;
            int fr1=mp[x];
            if(used.find(x)!=used.end())fr1=mp[x]-used[x];
            int c=k-x;
            if(c<0||mp.find(c)==mp.end())continue;
            int fr2=mp[c];
            if(used.find(c)!=used.end())fr2=mp[c]-used[c];
            int ans=0;
            if(x!=c)
            ans=min(fr1,fr2);
            else
            ans=fr1/2;
            used[x]+=ans;
            used[c]+=ans;
            fans+=ans;
        }
        return fans;
    }
};
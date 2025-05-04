class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int,int> mp;
        for(auto& it:dominoes){
            sort(it.begin(),it.end());
            mp[it[0]*10+it[1]]++;
        }
        int ans=0;
        for(auto it:mp){
            int q=it.second;
            q*=(it.second-1);
            q/=2;
            ans+=q;
        }
        return ans;
    }
};
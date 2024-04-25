class Solution {
public:
    int longestIdealString(string s, int k) {
        vector<int> mp(26,0);
        for(int i=0;i<s.size();i++)
        {
            char ch=s[i];
            int x=ch-'a';
            int c=0;
            for(int j=max(x-k,0);j<=min(x+k,25);j++)
            c=max(c,mp[j]);
            mp[x]=c+1;
        }
        int ans=INT_MIN;
        for(auto it:mp)
            ans=max(ans,it);
        return ans;
    }
};
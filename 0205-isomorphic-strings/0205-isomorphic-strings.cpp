class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<int,int> mp;
        unordered_set<int> st;
        for(int i=0;i<s.size();i++)
        {
            if(mp.find(s[i])==mp.end())
            {
            if(st.find(t[i])!=st.end())
            return false;
            mp[s[i]]=t[i];
            st.insert(t[i]);
            }
            else if(mp[s[i]]!=t[i])
            return false;
        }
        return  true;
    }
};
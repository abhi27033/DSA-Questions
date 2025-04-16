class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.size();
        vector<int> freq(26,0);
        for(int i=0;i<n/2;i++)
        freq[s[i]-'a']++;
        string ans;
        for(int i=0;i<26;i++)
        for(int j=0;j<freq[i];j++)
        ans+=(i+'a');
        string an=ans;
        reverse(an.begin(),an.end());
        if(n&1)
        ans+=s[n/2];
        ans+=an;
        return ans;
    }
};
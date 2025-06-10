class Solution {
public:
    int maxDifference(string s) {
        vector<int> freq(26,0);
        for(auto it:s)freq[it-'a']++;
        vector<int> fr;
        int ma=INT_MIN,mi=INT_MAX;
        for(int i=0;i<26;i++)if(freq[i]){
            if(freq[i]%2)ma=max(ma,freq[i]);
            else mi=min(mi,freq[i]);
        }
        return ma-mi;
    }
};
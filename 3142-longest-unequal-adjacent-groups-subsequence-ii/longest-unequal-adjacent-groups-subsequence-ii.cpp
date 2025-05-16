class Solution {
public:
int hamming(string& a,string& b){
    if(a.size()!=b.size())return 10;
    int ans=0;
    for(int i=0;i<a.size();i++)ans+=(a[i]!=b[i]);
    return ans;
}
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n=words.size();
        vector<int> prev(n,-1),dp(n,1);
        int ma=INT_MIN,idx=0;
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(hamming(words[i],words[j])==1&&groups[i]!=groups[j]&&dp[i]<dp[j]+1)
                {
                    prev[i]=j;
                    dp[i]=dp[j]+1;
                    if(ma<dp[i]){
                        ma=dp[i];
                        idx=i;
                    }
                }
            }
        }
        vector<string> ans;
        while(idx>=0){
            ans.push_back(words[idx]);
            idx=prev[idx];
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
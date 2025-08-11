class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<long long> ar;
        long long mod=1e9+7;
        int i=0;
        while(n){
            if(n&1)ar.push_back(1LL<<i);
            n>>=1;
            i++;
        }
        vector<int> ans;
        for(auto it:queries){
            long long x=1;
            for(int i=it[0];i<=it[1];i++)
                x=(x%mod*ar[i]%mod)%mod;
            ans.push_back((int)x);
        }
        return ans;
    }
};
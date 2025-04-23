class Solution {
public:
    int solve(int x){
        int sum=0;
        while(x){
            sum+=(x%10);
            x/=10;
        }
        return sum;
    }
    int countLargestGroup(int n) {
        unordered_map<int,int> mp;
        int ma=0;
        for(int i=1;i<=n;i++){
            int sum=solve(i);
            mp[sum]++;
            ma=max(ma,mp[sum]);
        }
        int ans=0;
        for(auto it:mp)
        {
            if(it.second==ma)
            ans++;
        }
        return ans;
    }
};
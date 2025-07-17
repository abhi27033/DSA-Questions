class Solution {
public:
int dp[1001][2][2];
vector<unordered_map<int,int>> nex;
    int solve(vector<int>& nums,int i,int c,int p,int& s){
        if(i>=nums.size())return 0;
        if(dp[i][c][p]!=-1)return dp[i][c][p];
        int pick=1,npick=0;
        int nexx=nums[i];
        if(c==0)
        nexx=s-nexx;
        else
        {
            nexx*=-1;
            nexx+=s;
        }
        if(nex[i].find(nexx)!=nex[i].end())
        pick=1+solve(nums,nex[i][nexx],1-c,1,s);
        if(p==0)
        npick=solve(nums,i+1,c,p,s);
        return dp[i][c][p]=max(pick,npick);
    }
    int maximumLength(vector<int>& nums, int k) {
        for(auto& it:nums)it%=k;
        int n=nums.size(),ans=1;
        nex.resize(n);
        unordered_map<int,int> mp;
        for(int i=n-1;i>=0;i--){
            nex[i]=mp;
            mp[nums[i]]=i;
        }
        for(int i=0;i<=2*k;i++){
        memset(dp,-1,sizeof(dp));
        int t=solve(nums,0,0,0,i);
        ans=max(ans,t);
        }
        return ans;
    }
};
class Solution {
public:
long long solve(long long a, long long b){
    long long x=log(a)/log(4);
    long long st=1,ans=0;
    for(int i=0;i<x;i++)st*=4;
    while(st<=b){
        int l=max(st,a);
        int r=min((st*4)-1,b);
        ans+=((r-l+1)*(x+1));
        st*=4;
        x++;
    }
    return (ans+1)/2;
}
    long long minOperations(vector<vector<int>>& queries) {
        long long ans=0;
        for(auto it:queries){
            ans+=solve(1LL*it[0],1LL*it[1]);
        }
        return ans;
    }
};
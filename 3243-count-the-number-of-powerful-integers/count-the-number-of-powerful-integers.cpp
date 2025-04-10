class Solution {
public:
long long solve(string& ub,string s,int l,int z){
    if(ub.size()==s.size()){
        return ub>=s;
    }
    if(ub.size()<s.size())return 0;
    int n=ub.size();
    int left=n-s.size();
    long long ans=0;
    for(int i=0;i<left;i++){
        int rem=left-i-1;
        long long x=pow(l+1,rem);
        x*=min(ub[i]-'0',l+1);
        ans+=x;
        if((ub[i]-'0')>l)return ans;
    }
    if(ub.substr(left,s.size())>=s) ans++;
    return ans;
}
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        string fin=to_string(finish);
        // cout<<fin<<endl;
        string sta=to_string(start-1);
        // cout<<sta<<endl;
        long long lh=solve(fin,s,limit,0);
        long long ll=solve(sta,s,limit,0);
        return lh-ll;
    }
};
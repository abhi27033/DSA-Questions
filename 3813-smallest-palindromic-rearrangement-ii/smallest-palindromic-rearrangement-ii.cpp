class Solution {
public:
using int128 = __int128_t;
vector<long long> fact;
long long mod=109930813984377167LL;//18 digit prime number is used here
//this is because the normal 1e9+7 gave WA since the crux is that k<=1e6 and to ensure this we can have the calculation in mod range
void computeFactorial(){
    int n=10000;
    fact.resize(n+1,1);
    for(int i=2;i<=n;i++)
    {
        fact[i]=((int128)fact[i-1]%mod*i)%mod;
    }
}
long long inv(long long base,long long exp){
    long long ans=1;
    while(exp>0){
        if(exp&1)
        {
        ans=((int128)ans*(int128)base%mod)%mod;
        exp--;
        }
        else
        {
        base=((int128)base%mod*(int128)base%mod)%mod;
        exp/=2;
        }
    }
    return ans;
}
long long generatePerm(vector<int>& freq){
    long long f=0;
    for(auto it:freq)
    f+=it;
    long long q=fact[f]%mod;
    for(auto it:freq)
    {
        if(it>0)
        q=((int128)q%mod*(int128)inv(fact[it],mod-2))%mod;
        //Modulous Inverse
        //s/=t inn mod is s*inv(t);
        //inv(t)=(t^(mod-2))%mod
    }
    return q;
}
    string smallestPalindrome(string s, int k) {
        vector<int> freq(26,0);
        int flg=0;
        if(s.size()&1)flg=1;
        for(int i=0;i<s.size()/2;i++)
        freq[s[i]-'a']++;
        string ans;
        computeFactorial();
        long long p=generatePerm(freq);
        if(k>p)return "";
        for(int i=0;i<s.size()/2;i++){
            for(int j=0;j<26;j++){
                if(freq[j]==0)continue;
                freq[j]--;
                long long x=generatePerm(freq);
                if(k<=x)
                {
                    ans+=(j+'a');
                    break;
                }
                k-=x;
                freq[j]++;
            }
        }
        string q=ans;
        reverse(q.begin(),q.end());
        if(flg)ans+=s[s.size()/2];
        ans+=q;
        return ans;
    }
};
/*
Total Permutations: 
For the string "AABBBC" (with 2 A's, 3 B's, and 1 C), the total number is  
6!/(2!×3!×1!)=60.
Fixing the First Letter:
If first letter is A:
Remaining letters: A, B, B, B, C →
Permutations =  
5!/(1!×3!×1!)=20.
If first letter is B:
Remaining letters: A, A, B, B, C →
Permutations =  
5!/(2!×2!×1!)=30.
If first letter is C:
Remaining letters: A, A, B, B, B →
Permutations =  
5!/(2!×3!)=10.
Determining the First Letter by k:
If k≤20: First letter is A.
If 20<k≤50: First letter is B.
If k>50: First letter is C.
*/
class Solution {
public:
long long gen_palin(int num,bool odd){
    long long ans=num;
    if(odd)
    num/=10;
    while(num)
    {
        ans=ans*10+(num%10);
        num/=10;
    }
    return ans;
}
bool check(long long num,int k){
    //base 10 to base k
    string ans;
    while(num){
        int rem=num%k;
        ans+=(rem+'0');
        num/=k;
    }
    string f=ans;
    reverse(f.begin(),f.end());
    //jo base k hai vo palindrome hai ki nahi
    return f==ans;
}
    long long kMirror(int k, int n) {
        long long ans=0;
        // base 10 me palindromes generate karo lex order me
        for(int digit=1;;digit*=10){
            for(int num=digit;num<digit*10;num++){
                if(n==0)return ans;
                //decimal numbers pehle odd length ke check karo
                long long palindrome=gen_palin(num,1);
                if(check(palindrome,k))
                {
                    ans+=palindrome;
                    n--;
                }
            }
            for(int num=digit;num<digit*10;num++){
                if(n==0)return ans;
                //decimal numbers phir even length ke check karo
                long long palindrome=gen_palin(num,0);
                if(check(palindrome,k))
                {
                    ans+=palindrome;
                    n--;
                }
            }
        }
        return ans;
    }
};
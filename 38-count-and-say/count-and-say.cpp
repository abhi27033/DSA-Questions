class Solution {
public:
    string solve(int n){
        if(n==1)return "1";
        string x=solve(n-1);
        string ans;
        int i=0;
        while(i<x.size()){
            char ch=x[i];
            int cnt=0;
            while(ch==x[i])
            i++,cnt++;
            ans+=(cnt+'0');
            ans+=ch;
        }
        return ans;

    }
    string countAndSay(int n) {
        return solve(n);
    }
};
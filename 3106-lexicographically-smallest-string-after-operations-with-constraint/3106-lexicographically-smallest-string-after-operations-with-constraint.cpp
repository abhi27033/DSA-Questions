class Solution {
public:
    bool solve(int i,string &ans,string &s,int k)
    {
        if(i==s.size()){
            return true;
        }
        for(char c='a';c<='z';c++)
        {
            int a=min(s[i]-c,((26-(s[i]-'a'))+(c-'a')));
            if(a<=k){
                ans.push_back(c);
                if(solve(i+1,ans,s,k-a)) return true;
                ans.pop_back();
            }
        }
        return false;
    }
    string getSmallestString(string s, int k) {
        string ans="";
        if(k==0) return s;
        solve(0,ans,s,k);
        return ans;
    }
};
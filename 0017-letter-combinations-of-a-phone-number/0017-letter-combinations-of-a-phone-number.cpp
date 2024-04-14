
class Solution {
public:
    void solve(int idx,string& d,string x,vector<string>& mp,vector<string>& ans)
    {
        if(idx>=d.size())
        {
            if(x.size())
            ans.push_back(x);
            return;
        }
        int m=d[idx]-'0';
        for(auto it:mp[m])
        {
            x+=it;
            solve(idx+1,d,x,mp,ans);
            x.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        vector<string> mapp(10);
        mapp[2]="abc";
        mapp[3]="def";
        mapp[4]="ghi";
        mapp[5]="jkl";
        mapp[6]="mno";
        mapp[7]="pqrs";
        mapp[8]="tuv";
        mapp[9]="wxyz";
        vector<string> ans;
        solve(0,digits,"",mapp,ans);
        return ans;
    }
};
class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans=0,c=0;
        for(auto it:s)
        {
            if(it=='(')
                c++;
            else
                c--;
            if(c<0)
            {
                c=0;
                ans++;
            }
        }
        ans+=c;
        return ans;
    }
};
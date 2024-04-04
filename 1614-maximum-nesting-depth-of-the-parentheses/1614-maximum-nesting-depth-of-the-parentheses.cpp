class Solution {
public:
    int maxDepth(string s) {
        int c=0,ans=0;
        for(auto it:s)
        {
            if(it=='(')
                c++;
            else if(it==')')
                c--;
            ans=max(ans,c);
        }
        return ans;
    }
};
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<char> st;
        string ans;
        for(auto it:s)
        {
            if(it=='(')
            {
                st.push(it);
                ans+=it;
            }else if(it>='a'&&it<='z')
                ans+=it;
            else
            {
                if(st.size()&&st.top()=='(')
                {
                st.pop();
                ans+=it;
                }
            }
            // cout<<ans<<endl;
        }
        int r=st.size();
        string fin;
        for(int i=ans.size()-1;i>=0;i--)
        {
            if(ans[i]=='('&&r)
                r--;
            else
                fin+=ans[i];
        }
        reverse(fin.begin(),fin.end());
        return fin;
    }
};
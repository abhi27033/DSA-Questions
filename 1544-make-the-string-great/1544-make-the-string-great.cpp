class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        for(auto it:s)
        {
            if(st.size()>0&&abs(st.top()-it)==32)
                st.pop();
            else
                st.push(it);
        }
        string ans;
        while(st.size())
        {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
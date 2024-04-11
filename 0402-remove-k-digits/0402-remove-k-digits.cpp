class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        for(auto it:num)
        {
                while(st.size()&&st.top()-'0'>it-'0'&&k>0)
                {
                    st.pop();
                    k--;
                }
                st.push(it);
        }
        string ans;
        while(st.size())
        {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        string a;
        int i=0;
        while(i<ans.size()&&ans[i]=='0')
            i++;
        while(i<ans.size()-k)
        {
            a+=ans[i];
            i++;
        }
        return a==""?"0":a;
    }
};
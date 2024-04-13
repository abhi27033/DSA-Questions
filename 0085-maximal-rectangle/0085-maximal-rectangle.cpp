class Solution {
public:
    int solve(vector<int> ar)
    {
        int n=ar.size();
        vector<int> ne(n+2,0);
        ne[0]=-1,ne[n+1]=-1;
        for(int i=1;i<=n;i++)
            ne[i]=ar[i-1];
        stack<int> st;
        vector<int> prev(n+2),next(n+2);
        st.push(0);
        for(int i=1;i<=n;i++)
        {
            while(st.size()&&ne[st.top()]>=ne[i])
                st.pop();
            prev[i]=st.top();
            st.push(i);
        }
        stack<int> s;
        s.push(n+1);
        for(int i=n;i>0;i--)
        {
            while(s.size()&&ne[s.top()]>=ne[i])
                s.pop();
            next[i]=s.top();
            s.push(i);
        }
        int ans=0;
        for(int i=1;i<=n;i++)
            ans=max(ans,ne[i]*(next[i]-prev[i]-1));
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<vector<int>> ar(n,vector<int>(m,0));
        for(int j=0;j<m;j++)
            ar[0][j]=matrix[0][j]=='0'?0:1;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]=='1')
                    ar[i][j]=ar[i-1][j]+1;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
            ans=max(ans,solve(ar[i]));
        return ans;
    }
};
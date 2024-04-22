class Solution {
public:
    bool check(string t,unordered_set<string>& vis,unordered_set<string>&dead)
    {
        return vis.find(t)==vis.end()&&dead.find(t)==dead.end();
    }
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string>vis,st;
        queue<pair<string,int>> q;
        for(auto it:deadends)
            st.insert(it);
        if(st.find("0000")!=st.end())return -1;
        q.push({"0000",0});
        vis.insert("0000");
        while(q.size())
        {
            int s=q.size();
            while(s--)
            {
               string f=q.front().first;
                int l=q.front().second;
                q.pop();
                // cout<<f<<" "<<l<<endl;
                if(f==target)
                    return l;
                string temp=f;
                for(int i=0;i<4;i++)
                {
                        char tt=temp[i];
                        temp[i]=((tt-'0'+1)%10)+'0';
                        if(check(temp,vis,st))
                        {
                            vis.insert(temp);
                            q.push({temp,l+1});
                        }
                        temp[i]=((tt-'0'+9)%10)+'0';
                        if(check(temp,vis,st))
                        {
                            vis.insert(temp);
                            q.push({temp,l+1});
                        }
                        temp[i]=tt;
                }
            }
        }
        return -1;
    }
};
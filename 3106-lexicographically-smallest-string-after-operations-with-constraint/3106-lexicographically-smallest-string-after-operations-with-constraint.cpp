class Solution {
public:
    string getSmallestString(string s, int k) {
        string ans;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='a')
                continue;
            int t=s[i]-'a';
            // cout<<k<<endl;
            if(k>=min(26-t,t))
            {
                k-=min(26-t,t);
                s[i]='a';
            }
            else
            {
                if(t>=k)
                    s[i]-=k;
               return s;
            }
            if(k==0)
                return s;
        }
        return s;
    }
};
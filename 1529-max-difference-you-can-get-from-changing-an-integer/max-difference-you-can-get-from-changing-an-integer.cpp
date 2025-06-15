class Solution {
public:
    int maxDiff(int num) {
        string s=to_string(num);
        char x='.';
        string ma=s,mi=s;
        for(auto& it:ma)
        {
        if(x=='.'&&it!='9')
        x=it;
        if(it==x)
        it='9';
        }
        x='.';
        for(auto& it:mi)
        {
        if(s[0]=='1'&&x=='.'&&it!='0'&&it!='1')
        x=it;
        if(s[0]!='1'&&x=='.'&&it!='0'&&it!='1')
        x=it;
        if(it==x){
            if(x==s[0])
            it='1';
            else
            it='0';
        }
        }
        int maa=stoi(ma),mii=stoi(mi);
        return maa-mii;
    }
};
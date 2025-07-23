class Solution {
public:
int removal(string& s, int flg){
    stack<char> stk;
    int ans=0;
    for(auto it:s){
        if(stk.size()){
            char ch1=(flg==0)?'a':'b';
            char ch2=(flg==0)?'b':'a';
            if(stk.top()==ch1&&it==ch2)
            {
                stk.pop();
                ans++;
                continue;
            }
        }
        stk.push(it);
    }
    string temp;
    while(stk.size())
    {
        temp+=stk.top();
        stk.pop();
    }
    reverse(temp.begin(),temp.end());
    s=temp;
    return ans;
}
    int maximumGain(string s, int x, int y) {
        int ans=0;
        if(x>=y){
        ans+=x*removal(s,0);
        ans+=y*removal(s,1);}
        else{
        ans+=y*removal(s,1);
        ans+=x*removal(s,0);
    }
    return ans;
    }
};
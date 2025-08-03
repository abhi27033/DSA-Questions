class Solution {
public:
bool isdigit(string& x){
    return x=="0"||x=="1"||x=="2"||x=="3"||x=="4"||x=="5"||x=="6"||x=="7"||x=="8"||x=="9";
}
    string decodeString(string s) {
        stack<string> stk;
        for(auto it:s){
            if(it==']'){
                vector<string> words;
                while(stk.size()&&stk.top()!="[")
                {
                    words.push_back(stk.top());
                    stk.pop();
                }
                reverse(words.begin(),words.end());
                string t;
                for(auto it:words)t+=it;
                stk.pop();
                string num;
                while(stk.size()&&isdigit(stk.top()))
                {
                    num+=stk.top();
                    stk.pop();
                }
                reverse(num.begin(),num.end());
                int n=stoi(num);
                string f;
                while(n--)
                f+=t;
                stk.push(f);
            }
            else
            {
                string x;
                x+=it;
                stk.push(x);
            }
        }
        vector<string> words;
        while(stk.size())
        {
            words.push_back(stk.top());
            stk.pop();
        }
        reverse(words.begin(),words.end());
        string t;
        for(auto it:words)t+=it;
        return t;
    }
};
class Solution {
public:
double eval(string &s, int &i) {
    stack<double> st;
    char op = '+';
    double num = 0;
    while (i < s.size()) {
        char c = s[i];
        if (isdigit(c)) {
            num = c - '0';
        }
        if (c == '(') {
            i++;
            num = eval(s, i); // evaluate sub-expression
        }
        // If operator or closing bracket or end
        if (!isdigit(c) || i == s.size() - 1) {
            if (op == '+') st.push(num);
            else if (op == '-') st.push(-num);
            else if (op == '*') { double t = st.top(); st.pop(); st.push(t * num); }
            else if (op == '/') {
                if (abs(num) < 1e-9) return 1e9; // invalid div by 0
                double t = st.top(); st.pop(); st.push(t / num);
            }
            op = c;
            num = 0;
        }

        if (c == ')') break;
        i++;
    }

    double res = 0;
    while (!st.empty()) {
        res += st.top();
        st.pop();
    }
    return res;
}

bool check(string exp) {
    int i = 0;
    double val = eval(exp, i);
    return abs(val - 24.0) < 1e-6;
}
    bool solve(vector<int>& cards,int idx,string exp,int brackets,int st){
        if(idx>=cards.size()){
            while(brackets--)
            exp+=')';
            return check(exp);
        }
        vector<char> op={'+','-','*','/'};
        bool flg=false;
        if(brackets>0&&st!=1){
            for(auto it:op){
                string newexp=exp;
                newexp+=')';
                newexp+=it;
                flg|=solve(cards,idx,newexp,brackets-1,1);
                // flg|=solve(cards,idx,exp+')',brackets-1,0);
            }
        }
        if(st){
            string newexp=exp;
            newexp+='(';
            newexp+=(cards[idx]+'0');
            flg|=solve(cards,idx+1,newexp,brackets+1,0);
            newexp=exp;
            newexp+=(cards[idx]+'0');
            flg|=solve(cards,idx+1,newexp,brackets,0);
        }
        else
        {
            for(auto it:op){
                string newexp=exp;
                newexp+=it;
                newexp+=(cards[idx]+'0');
                flg|=solve(cards,idx+1,newexp,brackets,0);
                newexp=exp;
                newexp+=it;
                newexp+='(';
                newexp+=(cards[idx]+'0');
                flg|=solve(cards,idx+1,newexp,brackets+1,0);
            }
        }
        return flg;
    }
    bool judgePoint24(vector<int>& cards) {
        sort(cards.begin(),cards.end());
        do{
            if(solve(cards,0,"",0,1))return true;
        }while(next_permutation(cards.begin(),cards.end()));
        return false;
    }
};
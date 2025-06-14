class Solution {
public:
    int minMaxDifference(int num) {
        vector<int> ar;
        string n=to_string(num);
        unordered_set<char> digits;
        int ma=INT_MIN,mi=INT_MAX;
        for(auto it:n)digits.insert(it);
        for(auto it:digits){
            for(char i='0';i<='9';i++){
                string temp=n;
                for(auto& itt:temp){
                    if(itt==it)
                    itt=i;
                }
                int t=stoi(temp);
                ma=max(ma,t);
                mi=min(mi,t);
            }
        }
        return ma-mi;
    }
};
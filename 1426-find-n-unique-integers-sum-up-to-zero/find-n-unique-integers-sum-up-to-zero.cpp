class Solution {
public:
    vector<int> sumZero(int n) {
        int x=n-1;
        x*=(x+1);
        x/=2;
        vector<int> ans;
        ans.push_back(-x);
        for(int i=1;i<n;i++)
        ans.push_back(i);
        return ans;
    }
};
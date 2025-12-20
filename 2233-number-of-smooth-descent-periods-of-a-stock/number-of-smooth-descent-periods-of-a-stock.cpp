class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        prices.push_back(-2);
        long long x=1,ans=0;
        for(int i=1;i<prices.size();i++)
        {
            if(prices[i]+1==prices[i-1])
            x++;
            else{
                x*=(x+1);
                x/=2;
                ans+=x;
                x=1;
            }
        }
        return ans;
    }
};
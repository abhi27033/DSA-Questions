class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        double ma=-1;
        int ans=-1;
        for(auto it:dimensions){
            int l=it[0],b=it[1];
            double d=(l*l+b*b);
            // cout<<d<<endl;
            if(d>=ma){
                if(d==ma)
                ans=max(ans,l*b);
                else
                ans=l*b;
                ma=d;
            }
        }
        return ans;
    }
};

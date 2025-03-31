class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        vector<long long> cuts;
        for(int i=1;i<weights.size();i++)
        cuts.push_back(weights[i]+weights[i-1]);
        sort(cuts.begin(),cuts.end());
        long long ma=weights[0]+weights.back();
        long long mi=ma;
        int c=k-1;
        for(int i=0;i<c;i++)
        mi+=cuts[i];
        c=k-1;
        int i=cuts.size()-1;
        while(i>=0)
        {
            if(c==0)break;
            ma+=cuts[i--];
            c--;
        }
        return ma-mi;
    }
};

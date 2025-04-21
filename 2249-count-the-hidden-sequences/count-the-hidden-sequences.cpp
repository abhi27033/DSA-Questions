class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long ma=differences[0],mi=differences[0];
        long long c=0;
        for(auto it:differences){
            c+=it;
            ma=max(ma,c);
            mi=min(mi,c);
        }
        long long l=lower-min(0LL,mi);
        long long h=upper-max(0LL,ma);
        return max(0LL,h-l+1);
    }
};
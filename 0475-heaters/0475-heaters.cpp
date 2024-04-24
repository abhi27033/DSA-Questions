class Solution {
public:
    bool ispossible(vector<int>& a,vector<int>& b,int r)
    {
        int i=0,j=0;
        while(i<b.size())
        {
            if(j==a.size())return false;
            long long hpos=a[j++];
            long long lpos=hpos-r;
            long long rpos=hpos+r;
            while(i<b.size()&&b[i]>=lpos&&b[i]<=rpos)
                i++;
        }
        return true;
    }
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int n=houses.size();
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        // ispossible(heaters,houses,498);
        long long l=0,ans=-1,h=LONG_MAX;
        while(l<=h)
        {
            long long m=l+(h-l)/2;
            if(ispossible(heaters,houses,m))
            {
                ans=m;
                h=m-1;
            }
            else
                l=m+1;
        }
        return ans;
    }
};
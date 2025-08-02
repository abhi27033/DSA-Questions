class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int,int> mp1,mp2,mp;
        long long mi=INT_MAX;
        for(auto it:basket1)
        {
            mp1[it]++;
            mp[it]++;
            mi=min(mi,1LL*it);
        }
        for(auto it:basket2)
        {
            mp2[it]++;
            mp[it]++;
            mi=min(mi,1LL*it);
        }
        vector<int> ar1,ar2;
        for(auto it:mp){
            if(it.second%2!=0)return -1;
            int freq=it.second/2;
            int ele=it.first;
            int fr1=0,fr2=0;
            if(mp1.find(ele)!=mp1.end())fr1=mp1[ele];
            if(mp2.find(ele)!=mp2.end())fr2=mp2[ele];
            if(freq<fr1){
                int left=fr1-freq;
                while(left--)
                ar1.push_back(ele);
            }
            if(freq<fr2){
                int left=fr2-freq;
                while(left--)
                ar2.push_back(ele);
            }
        }
        if(ar1.size()==0)return 0;
        sort(ar1.begin(),ar1.end());
        sort(ar2.rbegin(),ar2.rend());
        long long s=0;
        for(int i=0;i<ar1.size();i++){
            long long x=min(ar1[i],ar2[i]);
            x=min(x,2LL*mi);
            s+=x;
        }
        return s;
    }
};
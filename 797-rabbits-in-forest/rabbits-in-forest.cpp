class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> s;
        int ans=0;
        for(auto it:answers)
        {
            if(it)
            s[it]++;
            else ans++;
        }
        for(auto it:s){
            int x=it.first+1;
            ans+=(x*(it.second/x));
            if(it.second%x!=0)
            ans+=x;
        }
        return ans;
    }
};
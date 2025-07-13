class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        int j=0,ans=0,q=0;
        for(auto it:players){
            int x=lower_bound(trainers.begin()+j,trainers.end(),it)-trainers.begin();
            if(x<trainers.size())
            {
                j=max(j,x+1);
                ans++;
            }
        }
        return ans;
    }
};
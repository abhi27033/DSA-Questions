class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int ans=0;
        for(auto it:tickets)
        ans+=min(tickets[k],it);
        for(int i=k+1;i<tickets.size();i++)
            if(tickets[i]>=tickets[k])
                ans--;
        return ans;
    }
};
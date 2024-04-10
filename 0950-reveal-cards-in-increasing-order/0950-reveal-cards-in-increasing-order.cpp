class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(),deck.end());
        int n=deck.size();
        vector<int> ans(n,-1);
        int i=0,x=0,inc=1,flg=1;
        while(x<n)
        {
            i=0;
            // cout<<i<<" "<<flg<<endl;
            //first empty cell
            while(i<n)
            {
                if(ans[i]==-1)
                {
                if(flg)
                {
                    flg=0;
                    ans[i]=deck[x++];
                   
                }
                else
                    flg=1;
                }
                 i++;
            }
            for(auto it:ans)
                cout<<it<<" ";
            cout<<endl;
        }
        return ans;
    }
};
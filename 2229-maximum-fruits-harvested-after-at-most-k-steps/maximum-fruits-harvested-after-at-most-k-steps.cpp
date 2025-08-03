class Solution {
public:
    int bsearch(vector<vector<int>>& ar,int dist){
        int l=0,r=ar.size()-1,ans=-1;
        while(l<=r){
            int m=l+(r-l)/2;
            if(ar[m][0]<=dist){
                ans=m;
                l=m+1;
            }
            else
            r=m-1;
        }
        if(ans==-1)return 0;
        return ar[ans][1];
    }
    int bsearch1(vector<vector<int>>& ar,int dist){
        int l=0,r=ar.size()-1,ans=-1;
        while(l<=r){
            int m=l+(r-l)/2;
            if(ar[m][0]>=dist){
                ans=m;
                r=m-1;
            }
            else
            l=m+1;
        }
        if(ans==-1)return 0;
        return ar[ans][1];
    }
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        vector<vector<int>> ar,bk;
        for(int i=0;i<fruits.size();i++){
            if(fruits[i][0]>=startPos)
            ar.push_back({fruits[i][0],fruits[i][1]});
            else
            bk.push_back({fruits[i][0],fruits[i][1]});
        }
        for(int i=1;i<ar.size();i++)
            ar[i][1]+=ar[i-1][1];
        int ans=bsearch(ar,startPos+k),s=0;
        for(int i=bk.size()-1;i>=0;i--){
            int left=startPos-bk[i][0];
            if(left<=k){
                s+=bk[i][1];
                ans=max(ans,s);
                int posleft=k-2*left;
                // cout<<s<<" "<<posleft<<endl;
                if(posleft>=0)
                ans=max(ans,s+bsearch(ar,startPos+posleft));
            }
            else break;
        }
        for(int i=bk.size()-2;i>=0;i--)bk[i][1]+=bk[i+1][1];
        ans=max(ans,bsearch1(bk,startPos-k));
        for(int i=0;i<ar.size();i++){
            int left=ar[i][0]-startPos;
            if(left<=k){
                ans=max(ans,ar[i][1]);
                int posleft=k-2*left;
                if(posleft>=0)
                ans=max(ans,ar[i][1]+bsearch1(bk,startPos-posleft));
            }
        }
        return ans;
    }
};
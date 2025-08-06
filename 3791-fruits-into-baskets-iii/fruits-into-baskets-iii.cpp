class SegmentTree{
    private:
    vector<int> seg;
    public:
    SegmentTree(int n){
        seg.resize(4*n);
    }
    void build(int pos,int l,int r,vector<int>& ar){
        if(l>r)return;
        if(l==r){seg[pos]=ar[l];return;}
        int m=l+(r-l)/2;
        build(2*pos+1,l,m,ar);
        build(2*pos+2,m+1,r,ar);
        seg[pos]=max(seg[2*pos+1],seg[2*pos+2]);
    }
    int find(int pos,int l,int r,int& k){
        if(seg[pos]<k)return -1;
        if(l==r){
            seg[pos]=-1;
            return l;
        }
        int m=l+(r-l)/2;
        int ans=-1;
        if(seg[pos*2+1]>=k)
        ans=find(pos*2+1,l,m,k);
        else ans=find(pos*2+2,m+1,r,k);
        seg[pos]=max(seg[pos*2+2],seg[pos*2+1]);
        return ans;
    }
};
class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        SegmentTree st(fruits.size());
        int ans=0;
        st.build(0,0,baskets.size()-1,baskets);
        for(auto it:fruits){
            int f=st.find(0,0,baskets.size()-1,it);
            ans+=(f==-1);
        }
        return ans;
    }
};
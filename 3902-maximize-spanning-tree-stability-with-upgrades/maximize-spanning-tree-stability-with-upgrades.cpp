class DSU{
private:
    vector<int> rank,par;
public:
    DSU(int n){
        rank.resize(n,1);
        par.resize(n,0);
        for(int i=0;i<n;i++)par[i]=i;
    }
    int find(int u){
        if(par[u]!=u)
        return par[u]=find(par[u]);
        return u;
    }
    bool unite(int u,int v){
        int uu=find(u);
        int vv=find(v);
        if(uu!=vv){
            int r1=rank[uu],r2=rank[vv];
            if(r1<r2){
                par[uu]=vv;
            }
            else if(r2<r1){
                par[vv]=uu;
            }
            else{
                par[uu]=vv;
                rank[vv]++;
            }
            return true;
        }
        return false;
    }
};
class Solution {
public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        DSU d(n);
        unordered_set<int> st;
        int ans=INT_MAX;
        for(auto it:edges){
            if(it[3]==1)
            {
                if(d.unite(it[0],it[1]))
                {
                    ans=min(ans,it[2]);
                    st.insert(it[0]);
                    st.insert(it[1]);
                }
                else
                return -1;
            }
        }
        // cout<<ans<<endl;
        vector<int> vt;
        sort(edges.begin(),edges.end(),[&](const vector<int>& a,const vector<int>& b){return a[2]>b[2];});
        for(auto it:edges){
            if(it[3]==0&&d.unite(it[0],it[1]))
            {
                vt.push_back(it[2]);
                st.insert(it[0]);
                st.insert(it[1]);
            }
        }
        for(int i=vt.size()-1;i>=0;i--){
            if(k>0){
                ans=min(ans,2*vt[i]);
                k--;
            }
            else
            ans=min(ans,vt[i]);
        }
        int supreme=d.find(0);
        for(int i=1;i<n;i++)
        if(supreme!=d.find(i))return -1;
        if(st.size()!=n)return -1;
        return ans;
    }
};
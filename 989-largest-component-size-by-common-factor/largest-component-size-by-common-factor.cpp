class DSU{
    private:
    vector<int> rank;
    vector<int> parent;
    public:
    DSU(int size){
        rank.resize(size+1,1);
        parent.resize(size+1,0);
        for(int i=1;i<=size;i++)
        parent[i]=i;
    }
    int findParent(int node){
        if(parent[node]!=node)
        return parent[node]=findParent(parent[node]);
        return node;
    }
    // 1 if did union
    // 0 if no union
    int DoUnion(int node1,int node2){
        int parentNode1=findParent(node1);
        int parentNode2=findParent(node2);
        if(parentNode1==parentNode2)
        return 0;
        int rankNode1=rank[parentNode1];
        int rankNode2=rank[parentNode2];
        if(rankNode1<rankNode2){
            parent[parentNode1]=parentNode2;
        }
        else if(rankNode1>rankNode2){
            parent[parentNode2]=parentNode1;
        }
        else{
            rank[parentNode1]++;
            parent[parentNode2]=parentNode1;
        }
        return 1;
    }
};
class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
        int totalComponents=0;
        DSU d(3*1e5);
        for(int num:nums){
            for(int i=2;i*i<=num;i++){
                if(num%i==0){
                    totalComponents+=d.DoUnion(i,num);
                    totalComponents+=d.DoUnion(num/i,num);
                }
            }
        }
        int largestSize=INT_MIN;
        unordered_map<int,int> commonParent;
        for(int num : nums){
            int root = d.findParent(num);
            commonParent[root]++;
            largestSize = max(largestSize, commonParent[root]);
        }
        return largestSize;
        
   }
};
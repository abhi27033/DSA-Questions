class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        set<pair<int,int>> vis;
        vis.insert({0,0});
        int ans=0;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        pq.push({0,0,0});
        vector<int> dx={1,0,-1,0};
        vector<int> dy={0,1,0,-1};
        while(pq.size()){
            int cost=pq.top()[0];
            int i=pq.top()[1];
            int j=pq.top()[2];
            pq.pop();
            if(i==moveTime.size()-1&&j==moveTime[0].size()-1)return cost;
            for(int k=0;k<4;k++){
                int ii=i+dx[k];
                int jj=j+dy[k];
                if(ii>=0&&jj>=0&&ii<moveTime.size()&&jj<moveTime[0].size()&&vis.find({ii,jj})==vis.end()){
                    pq.push({max(moveTime[ii][jj],cost)+1,ii,jj});
                    vis.insert({ii,jj});
                }
            }
        }
        return -1;
    }
};
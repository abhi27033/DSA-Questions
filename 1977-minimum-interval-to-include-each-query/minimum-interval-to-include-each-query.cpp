class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ar;
        for(int i=0;i<queries.size();i++)
        ar.push_back({queries[i],i});
        sort(ar.begin(),ar.end());
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        vector<int> ans(ar.size());
        int i=0;
        for(auto itt:ar){
            int it=itt[0];
            while(i<intervals.size()&&intervals[i][0]<=it){
                pq.push({intervals[i][1]-intervals[i][0]+1,i});
                i++;
            }
            while(pq.size()&&intervals[pq.top()[1]][1]<it)pq.pop();
            if(pq.size())ans[itt[1]]=(pq.top()[0]);
            else ans[itt[1]]=(-1);
        }
        return ans;
    }
};
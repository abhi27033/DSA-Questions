class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),[](vector<int>& a,vector<int>& b){if(a[0]==b[0])return a[1]>b[1];return a[0]<b[0];});
        int ans=0;
        for(int i=0;i<points.size();i++)
        {
            int mi=INT_MIN;
            for(int j=i+1;j<points.size();j++){
                if(!(points[j][1]>points[i][1]&&points[i][0]!=points[j][0]))
                if(mi<points[j][1])
                ans++;
                if(points[j][1]<=points[i][1])mi=max(mi,points[j][1]);
            }
        }
        return ans;
    }
};
class Solution {
public:
    int check(vector<vector<int>>& pts,int x1,int y1,int x2,int y2,int ii, int jj){
        for(int i=0;i<pts.size();i++)
        {
            if(i==ii||i==jj)continue;
            if(x1<=pts[i][0]&&pts[i][0]<=x2&&min(y1,y2)<=pts[i][1]&&pts[i][1]<=max(y1,y2))return 0;
        }
        return 1;
    }
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int ans=0;
        for(int i=0;i<points.size();i++)
        {
            for(int j=i+1;j<points.size();j++){
                if(points[j][1]>points[i][1]&&points[i][0]!=points[j][0])continue;
                ans+=check(points,points[i][0],points[i][1],points[j][0],points[j][1],i,j);
            }
        }
        return ans;
    }
};
class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<vector<int>> x(n+1, {INT_MAX, INT_MIN}), y(n+1, {INT_MAX, INT_MIN});
        for (auto& it : buildings) {
            int dx = it[0], dy = it[1];
            x[dx][0] = min(x[dx][0], dy);
            x[dx][1] = max(x[dx][1], dy);
            y[dy][0] = min(y[dy][0], dx);
            y[dy][1] = max(y[dy][1], dx);
        }
        
        int ans = 0;
        for (auto& it : buildings) {
            int dx = it[0], dy = it[1];
            if (dy > x[dx][0] && dy < x[dx][1] && dx > y[dy][0] && dx < y[dy][1]) {
                ans++;
            }
        }
        return ans;
    }
};
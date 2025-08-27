#include <bits/stdc++.h>
using namespace std;

struct State {
    int len, i, j, dir, turn;
    // keep comparator if you ever want to switch back; not used by buckets
    bool operator<(const State& o) const { return len < o.len; }
};

class Solution {
public:
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        static int vis[505][505][4][2];
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                for(int d=0; d<4; d++)
                    for(int t=0; t<2; t++)
                        vis[i][j][d][t] = -1;

        int maxCap = max(n, m) + 2;            // safe cap for len
        vector<vector<State>> buckets(maxCap); // buckets[len] contains states with that len
        int curMax = 0;

        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    for(int d=0; d<4; d++){
                        vis[i][j][d][0] = 1;
                        buckets[1].push_back({1,i,j,d,0});
                    }
                    ans = 1;
                    curMax = max(curMax, 1);
                }
            }
        }

        int dc[4][2] = {{-1,1},{1,1},{1,-1},{-1,-1}};
        int nextVal[3] = {2,2,0};

        // process: always take a state with the largest len (curMax)
        while(curMax > 0){
            // find next non-empty bucket (curMax will only decrease when empty)
            while(curMax > 0 && buckets[curMax].empty()) curMax--;
            if(curMax == 0) break;

            // pop one state from buckets[curMax]
            State cur = buckets[curMax].back();
            buckets[curMax].pop_back();
            int len = cur.len, i = cur.i, j = cur.j, dir = cur.dir, turn = cur.turn;

            // If this state is stale (vis changed to larger), skip
            if(vis[i][j][dir][turn] != len) continue;

            int ni = i + dc[dir][0];
            int nj = j + dc[dir][1];
            if(ni>=0 && nj>=0 && ni<n && nj<m){
                if(nextVal[grid[i][j]] == grid[ni][nj] && vis[ni][nj][dir][turn] < len+1){
                    vis[ni][nj][dir][turn] = len+1;
                    ans = max(ans, len+1);
                    if(ans == max(n, m)) return ans;
                    int newlen = len+1;
                    if(newlen < maxCap){
                        buckets[newlen].push_back({newlen, ni, nj, dir, turn});
                        curMax = max(curMax, newlen);
                    }
                }
            }

            if(turn == 0){
                int ndir = (dir + 1) % 4;
                int nturn = 1;
                ni = i + dc[ndir][0];
                nj = j + dc[ndir][1];
                if(ni>=0 && nj>=0 && ni<n && nj<m){
                    if(nextVal[grid[i][j]] == grid[ni][nj] && vis[ni][nj][ndir][nturn] < len+1){
                        vis[ni][nj][ndir][nturn] = len+1;
                        ans = max(ans, len+1);
                        if(ans == max(n, m)) return ans;
                        int newlen = len+1;
                        if(newlen < maxCap){
                            buckets[newlen].push_back({newlen, ni, nj, ndir, nturn});
                            curMax = max(curMax, newlen);
                        }
                    }
                }
            }
        }
        return ans;
    }
};

#define pii pair<int,pair<int,int>>

class Solution {
public:
    bool check(int r, int c, int n)
    {
        return (r >= 0 && c >= 0 && r < n && c < n);
    }
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({grid[0][0],{0,0}});
        int dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        int ans = 0;
        int n = grid.size();
        vector<vector<int>> vis(n, vector<int> (n,0));
        vis[0][0] = 1;

        while(!pq.empty())
        {
            auto it = pq.top();
            int dep = it.first;
            int r = it.second.first;
            int c = it.second.second;
            ans = max(ans, dep);
            if(r == n-1 && c == n-1) return ans;
            pq.pop();

            for(auto [dr,dc] : dirs)
            {
                int nr = r + dr;
                int nc = c + dc;

                if(check(nr,nc,n) && !vis[nr][nc])
                {
                    vis[nr][nc] = 1;
                    // if(nr == (n-1) && nc == (n-1)) return ans = max(ans, grid[nr][nc]);
                    pq.push({grid[nr][nc],{nr,nc}});
                }
            }
        }
        return ans;
    }
};
class Solution {
public:

    bool check(int r, int c, int m, int n)
    {
        return (r >= 0 && c >= 0 && r < m && c < n);
    }

    int dfs(vector<vector<int>> &grid, vector<vector<int>> &vis, int r, int c)
    {
        int m = grid.size();
        int n = grid[0].size();
        vis[r][c] = 1;
        int area = 1;

        int dir[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        for(auto [rd, cd] : dir)
        {
            int nr = r + rd;
            int nc = c + cd;
            if(check(nr,nc,m,n) && grid[nr][nc] == 1 && vis[nr][nc] == 0)
            {
                area += dfs(grid,vis,nr,nc);
            }
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int> (n,0));
        int ans = 0;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 1 && vis[i][j] == 0)
                {
                    int area = dfs(grid,vis,i,j);
                    ans = max(area, ans);
                }
            }
        }
        return ans;
    }
};
class Solution {
public:

    
    int countServers(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n,0));

        for(int i=0; i<m; i++)
        {
            int cntvis = 0;
            int cnt = 0;
            int col = -1;
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 1)
                {
                    cnt++;
                    if(vis[i][j] == 0)
                    {
                        cntvis++;
                        vis[i][j] = 1;
                        col = j;
                    }
                }
            }

            if(cntvis == 0) continue;
            
                if(cnt > 1) ans += cntvis;
                if(cnt == 1 && cntvis == 1)
                {
                    vis[i][col] = 0;
                }
            
        }

        for(int i=0; i<n; i++)
        {
            int cntvis = 0;
            int cnt = 0;
            int row = -1;
            for(int j=0; j<m; j++)
            {
                if(grid[j][i] == 1)
                {
                    cnt++;
                    if(vis[j][i] == 0)
                    {
                        cntvis++;
                        vis[j][i] = 1;
                        row = j;
                    }
                }
            }

            if(cntvis == 0) continue;
            if(cnt > 1) ans += cntvis;
            if(cnt == 1 && cntvis == 1)
            {
                vis[row][i] = 0;
            }
        }
        return ans;
    }
};
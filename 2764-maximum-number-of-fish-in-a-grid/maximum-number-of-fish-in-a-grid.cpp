class Solution {
public:

    bool check(int r,int c, int n, int m)
    {
        return (r >= 0 && r < n && c >= 0 && c < m); 
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        int rd[] = {0,1,0,-1};
        int cd[] = {1,0,-1,0};
        int ans = 0;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j] != 0 && vis[i][j] == 0)
                {
                    vis[i][j] = 1;
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    int temp = grid[i][j];

                    while(!q.empty())
                    {
                        auto it = q.front();
                        int r = it.first;
                        int c = it.second;
                        // cout << r << " " << c << endl;
                        q.pop();

                        for(int k=0; k<4; k++)
                        {
                            int nr = r + rd[k];
                            int nc = c + cd[k];

                            if(check(nr,nc,n,m) && vis[nr][nc] == 0 && grid[nr][nc] != 0)
                            {
                                vis[nr][nc] = 1;
                                temp += grid[nr][nc];
                                q.push({nr,nc});
                            }
                        }
                    }
                    // cout << "Temp - " << temp << endl;

                    ans = max(temp, ans);
                }
            }
        }
        return ans;
    }
};
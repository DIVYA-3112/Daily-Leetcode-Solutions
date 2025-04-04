class Solution {
public:

    bool check(int r, int c, int m, int n)
    {
        return (r >= 0 && c >= 0 && r < m && c < n);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> vis(m, vector<int> (n, 0));
        
        // pacific ocean;
        queue<pair<int,int>> q;
        for(int i=0; i<n; i++)
        {
            q.push({0,i});
            vis[0][i] = 1;
        }

        for(int j=0; j<m; j++)
        {
            q.push({j,0});
            vis[j][0] = 1;
        }

        int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        while(!q.empty())
        {
            auto [r,c] = q.front();
            int h = mat[r][c];
            q.pop();

            for(auto [rd,cd] : dir)
            {
                int nr = r + rd;
                int nc = c + cd;

                if(check(nr,nc,m,n) && mat[nr][nc] >= h && vis[nr][nc] == 0)
                {
                    vis[nr][nc] = 1;
                    q.push({nr,nc});
                }
            }
        }

        for(int i=0; i<n; i++)
        {
            q.push({m-1,i});
            vis[m-1][i] += 2;
        }

        for(int j=0; j<m-1; j++)
        {
            q.push({j,n-1});
            vis[j][n-1] += 2;
        }
        vector<vector<int>> ans;

        while(!q.empty())
        {
            auto [r,c] = q.front();
            int h = mat[r][c];
            q.pop();

            for(auto [rd,cd] : dir)
            {
                int nr = r + rd;
                int nc = c + cd;

                if(check(nr,nc,m,n) && mat[nr][nc] >= h && vis[nr][nc] < 2)
                {
                    vis[nr][nc] += 2;
                    q.push({nr,nc});
                }
            }
        }

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(vis[i][j] >= 3) ans.push_back({i,j});
            }
        }
        return ans;
    }
};
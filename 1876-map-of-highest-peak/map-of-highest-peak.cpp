class Solution {
public:

    bool check(int r, int c, int m, int n)
    {
        if(r >= 0 && r < m && c >= 0 && c < n) return true;
        return false;
    }
    vector<vector<int>> highestPeak(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> ans(m,vector<int>(n,-1));

        queue<pair<int,pair<int,int>>> q;

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(mat[i][j] == 1)
                {
                    ans[i][j] = 0;
                    q.push({0,{i,j}});
                }
            }
        }

        int rd[] = {0,-1,0,1};
        int cd[] = {1,0,-1,0};

        while(!q.empty())
        {
            auto it = q.front();
            int h = it.first;
            int r = it.second.first;
            int c = it.second.second;

            // cout << r << " " << c << " " << h << endl;

            q.pop();
            
            for(int k=0; k<4; k++)
            {
                int nr = r + rd[k];
                int nc = c + cd[k];
                if(check(nr,nc,m,n) && ans[nr][nc] == -1)
                {
                    ans[nr][nc] = h + 1;
                    q.push({h+1, {nr,nc}});
                }
            }
        }
        return ans;
    }
};
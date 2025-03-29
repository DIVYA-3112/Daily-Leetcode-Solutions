#define pii pair<int,int>
#define ipii pair<int, pii>

class Solution {
public:
    bool check(int r, int c, int m, int n) {
        return (r < m && c < n && r >= 0 && c >= 0);
    }

    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& que) {
        int m = grid.size(), n = grid[0].size();
        int len = que.size();

        vector<pii> ind(len);
        vector<int> res(len, 0);
        vector<vector<int>> vis(m, vector<int>(n, 0));

        // Direction vectors for movement
        int rd[] = {0, 1, 0, -1};
        int cd[] = {1, 0, -1, 0};

        // Min-heap (priority queue) for grid traversal
        priority_queue<ipii, vector<ipii>, greater<ipii>> pq;

        // Store query values with their original index
        for (int i = 0; i < len; i++) {
            ind[i] = {que[i], i};
        }
        
        // Sort queries in increasing order
        sort(ind.begin(), ind.end());

        // Start BFS from (0,0)
        pq.push({grid[0][0], {0, 0}});
        vis[0][0] = 1;  // Mark as visited

        int cnt = 0, i = 0;

        // Process queries in sorted order
        for (auto [queryValue, queryIndex] : ind) {
            // Expand grid cells until we reach a value >= queryValue
            while (!pq.empty() && pq.top().first < queryValue) {
                auto [val, pos] = pq.top();
                pq.pop();

                auto [r, c] = pos;
                cnt++; // Increment count only when processing a valid cell

                // Explore 4 directions
                for (int k = 0; k < 4; k++) {
                    int nr = r + rd[k], nc = c + cd[k];

                    if (check(nr, nc, m, n) && !vis[nr][nc]) {
                        vis[nr][nc] = 1;  // Mark as visited BEFORE pushing
                        pq.push({grid[nr][nc], {nr, nc}});
                    }
                }
            }
            // Assign result for this query
            res[queryIndex] = cnt;
        }
        
        return res;
    }
};

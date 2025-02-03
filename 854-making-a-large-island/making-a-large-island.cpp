class Solution {
public:
    vector<int> parent, size;  // Union-Find arrays

    int find(int x) {  // Find with path compression
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unionSet(int x, int y) {  // Union by size
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (size[rootX] > size[rootY]) {
                parent[rootY] = rootX;
                size[rootX] += size[rootY];
            } else {
                parent[rootX] = rootY;
                size[rootY] += size[rootX];
            }
        }
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        parent.resize(n * n);
        size.resize(n * n, 1);

        // Initialize Union-Find
        for (int i = 0; i < n * n; i++) parent[i] = i;

        int directions[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        
        // Step 1: Find islands and union connected components
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int index = i * n + j;
                    for (auto dir : directions) {
                        int ni = i + dir[0], nj = j + dir[1];
                        if (ni >= 0 && ni < n && nj >= 0 && nj < n && grid[ni][nj] == 1) {
                            unionSet(index, ni * n + nj);
                        }
                    }
                }
            }
        }

        // Step 2: Store island sizes
        unordered_map<int, int> islandSize;
        int maxIsland = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int root = find(i * n + j);
                    islandSize[root] = size[root];
                    maxIsland = max(maxIsland, size[root]); // Get max island size
                }
            }
        }

        // Step 3: Try flipping each 0 and find the max island
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int> seen;
                    int newSize = 1; // The flipped cell itself

                    for (auto dir : directions) {
                        int ni = i + dir[0], nj = j + dir[1];
                        if (ni >= 0 && ni < n && nj >= 0 && nj < n && grid[ni][nj] == 1) {
                            int root = find(ni * n + nj);
                            if (seen.find(root) == seen.end()) {
                                newSize += islandSize[root];
                                seen.insert(root);
                            }
                        }
                    }
                    maxIsland = max(maxIsland, newSize);
                }
            }
        }

        return maxIsland == 0 ? n * n : maxIsland;
    }
};

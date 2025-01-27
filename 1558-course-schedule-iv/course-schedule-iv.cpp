class Solution {
public:

    vector<vector<int>> funadj(vector<vector<int>> &edges, int n)
    {
        vector<vector<int>> adj(n, vector<int>(n,0));
        for(auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            adj[u][v] = 1;
        }
        return adj;
    }
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        vector<vector<int>> adj = funadj(edges, n);
        for(int k=0; k<n; k++)
        {
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<n; j++)
                {
                    adj[i][j] = (adj[i][j] || (adj[i][k] && adj[k][j]));
                }
            }
        }

        int q = queries.size();
        vector<bool> ans;
        for(int i=0; i<q; i++)
        {
            if(adj[queries[i][0]][queries[i][1]]) ans.push_back(true);
            else ans.push_back(false); 
        }
        return ans;
    }
};
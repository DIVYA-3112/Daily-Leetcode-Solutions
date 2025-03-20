class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int q = queries.size();
        vector<vector<pair<int,int>>> adj(n);
        int e = edges.size();

        for(int i=0; i<e; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];

            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }

        // <component id -> bitwise AND;
        unordered_map<int,int> mp;
        vector<int> vis(n,0);
        vector<int> cid(n,0);
        int id = 1;
        for(int i=0; i<n; i++)
        {
            // int cost = INT_MAX;
            if(!vis[i])
            {
                vis[i] = 1;
                cid[i] = id;
                unsigned int cost = INT_MAX;

                queue<int> q;
                q.push(i);

                while(!q.empty())
                {
                    int v = q.front();
                    
                    q.pop();

                    for(auto it : adj[v])
                    {
                        int v = it.first;
                        int wt = it.second;
                        cost = (cost & wt);
                        if(!vis[v])
                        {
                            q.push(v);
                            vis[v] = 1;
                            cid[v] = id;
                        }
                    }
                }
                mp[id] = cost;
                id++;
            }
        }
        vector<int> ans(q,0);

        for(int i=0; i<q; i++)
        {
            int u = queries[i][0];
            int v = queries[i][1];

            if(cid[u] != cid[v])
            {
                ans[i] = -1;
                // continue;
            }
            else
            {
                ans[i] = mp[cid[u]];
            }
        }
        return ans;
    }
};
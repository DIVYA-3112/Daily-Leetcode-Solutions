class Solution {
public:

    bool toposort(vector<vector<int>> &adj, vector<int> &vis, vector<int> &temp, int ind, stack<int> &st)
    {
        vis[ind] = 1;
        temp[ind] = 1;
        for(int i : adj[ind])
        {
            if(temp[i]) return true;
            if(!vis[i])
            {
                if(toposort(adj, vis, temp, i, st)) return true;
            }
        }
        temp[ind] = 0;
        st.push(ind);
        return false;
    }
    bool canFinish(int V, vector<vector<int>>& pre) {
        // topo sort using dfs
        // create adj list
        vector<vector<int>> adj(V);
        int n = pre.size();

        for(int i=0; i<n; i++)
        {
            int u = pre[i][0];
            int v = pre[i][1];

            adj[v].push_back(u);
        }

        vector<int> vis(V,0);
        vector<int> temp(V,0);
        stack<int> st;
        for(int i=0; i<V; i++)
        {
            if(!vis[i])
            {
                if(toposort(adj, vis, temp, i, st)) return false;
            }
        }
        return true;
    }
};
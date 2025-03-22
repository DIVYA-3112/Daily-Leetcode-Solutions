class DSU
{
    public:
    vector<int> par,rank;
    DSU(int n)
    {
        par.resize(n);
        rank.resize(n,0);
        for(int i=0; i<n; i++) par[i] = i;
    }

    void uni(int u, int v)
    {
        int pu = findPar(u);
        int pv = findPar(v);

        if(pu == pv) return;

        if(rank[pu] > rank[pv])
        {
            par[pv] = pu;
        }
        else if(rank[pv] > rank[pu])
        {
            par[pu] = pv;
        }
        else
        {
            par[pu] = pv;
            rank[pv]++;
        }
        return;
    }

    int findPar(int u)
    {
        if(par[u] != u) return par[u] = findPar(par[u]);
        else return u;
    }
};

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        // adj list;
        vector<vector<int>> adj(n);
        int e = edges.size();
        DSU dsu(n);

        for(int i=0; i<e; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
            dsu.uni(u,v);
        }

        set<int> st;
        for(int i=0; i<n; i++)
        {
            st.insert(dsu.par[i]);
        }
        int ans = 0;
        // vector<int> vis(n,0);
        vector<int> v(st.begin(), st.end());
        for(int i=0; i<v.size(); i++)
        {
            int k = v[i];
            int len = adj[k].size();
            bool flag = true;
            int cnt = 0;
            vector<int> vis(n,0);
            vis[k] = 1;
            for(auto it : adj[k])
            {
                vis[it] = 1;
            }
            for(auto it : adj[k])
            {
                cnt++;
                if(adj[it].size() != len)
                {
                    flag = false;
                    break;
                }
                for(auto i : adj[it])
                {
                    if(vis[i] == 0)
                    {
                        flag = false;
                        break;
                    }
                }
            }
            if(flag)
            {
                if(len == cnt) ans++;
            }
        }
        return ans;

        // union find;
    }
};
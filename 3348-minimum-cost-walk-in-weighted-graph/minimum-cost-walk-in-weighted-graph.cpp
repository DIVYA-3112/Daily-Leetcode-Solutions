class DSU
{
    vector<int> rank;
    vector<int> par;
    public :
    DSU(int n)
    {
        rank.resize(n);
        par.resize(n);

        for(int i=0; i<n; i++) par[i] = i;
    }

    int findPar(int u)
    {
        if(par[u] != u) 
        {
            return par[u] = findPar(par[u]);
            // return par[u];
        }
        else return u;
    }

    void Union(int u, int v)
    {
        int pu = findPar(u);
        int pv = findPar(v);

        if(pu == pv) return;

        if(rank[pu] > rank[pv])
        {
            par[pv] = pu;
        }
        else if(rank[pu] < rank[pv])
        {
            par[pu] = pv;
        }
        else
        {
            par[pu] = pv;
            rank[pv] += 1;
        }
        return;
    }
};

class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int q = queries.size();
        vector<vector<pair<int,int>>> adj(n);
        vector<unsigned int> cc(n, -1); 
        int e = edges.size();
        for(int i=0; i<e; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];

            adj[u].push_back({v,wt});
        }

        DSU dsu(n);

        for(int i=0; i<e; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];

            dsu.Union(u,v);
        }

        for(int i=0; i<e; i++)
        {
            int u = edges[i][0];
            int wt = edges[i][2];
            int pu = dsu.findPar(u);
            cc[pu] = (cc[pu] & wt);
        }
        vector<int> ans(q,0);

        for(int i=0; i<q; i++)
        {
            int u = queries[i][0];
            int v = queries[i][1];

            int pu = dsu.findPar(u);
            int pv = dsu.findPar(v);

            if(pu != pv)
            {
                ans[i] = -1;
                // continue;
            }
            else
            {
                int pu = dsu.findPar(u);
                ans[i] = cc[pu];
            }
        }
        return ans;
    }
};
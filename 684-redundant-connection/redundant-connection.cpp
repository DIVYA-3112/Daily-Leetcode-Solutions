class DSU
{
    public : 
    vector<int> rank;
    vector<int> par;
    DSU(int n)
    {
        rank.resize(n+1);
        par.resize(n+1);
        for(int i=0; i<=n; i++) par[i] = i;
    }

    bool uni(int u, int v)
    {
        int pu = findpar(u);
        int pv = findpar(v);

        if(pu == pv) return false;

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
            rank[pu]++;
            par[pv] = pu;
        }
        return true;
    }

    int findpar(int u)
    {
        if(u == par[u]) return u;
        return par[u] = findpar(par[u]);
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU dsu(n);
        for(int i=0; i<n; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            if(!dsu.uni(u,v)) return {u,v};
        }
        return {0,0};
    }
};
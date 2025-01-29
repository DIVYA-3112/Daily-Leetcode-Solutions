class DSU
{
    private :
    vector<int> rank,parent;

    public : 
    DSU(int n)
    {
        rank.resize(n+1,0);
        parent.resize(n+1);

        for(int i=0; i<n; i++)
        {
            parent[i] = i;
        }
    }

    int find(int x)
    {
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void join(int u, int v)
    {
        int pu = parent[u];
        int pv = parent[v];

        if(pu == pv) return;

        if(rank[pu] > rank[pv])
        {
            parent[pv] = pu; 
        }
        else if(rank[pv] > rank[pu])
        {
            parent[pu] = pv;
        }
        else
        {
            parent[pu] = pv;
            rank[pv]++;
        }
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

            if(dsu.find(u) == dsu.find(v)) return edges[i];

            dsu.join(u,v);
        }

        return {-1};
    }
};